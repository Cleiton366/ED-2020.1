#include "ordered_list.hpp"
#include <limits>
#include <iostream>
using namespace std;
//typedef no_encadeado* no_encadeado;

// Construir lista vazia
list::list() {
    this->primeiro = nullptr;
    this->tamanho = 0;
}

// Construir lista com "tamanho" cópias do valor "inicial".
list::list(unsigned int tamanho, int inicial) {
   this->tamanho = tamanho;
   int indice = 0;
   while(indice <= tamanho){
       if(indice == 0) {
           no_encadeado* no = new no_encadeado(inicial, this->primeiro);
           this->primeiro = no;
           indice ++;
       }
       no_encadeado* no = this->primeiro;
       no->elemento = inicial;
       no = no->proximo;
       indice++;
   }
}


// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção. Sempre deve executar a inserção.

bool list::inserir(int elemento){
    if(this->primeiro == nullptr){
       no_encadeado* novo_no = new no_encadeado(elemento);
       this->primeiro = novo_no;
       novo_no->proximo = nullptr;
       this->tamanho++;
       return true;
    } else{
        no_encadeado* no = this->primeiro;
        while(no->proximo != nullptr){
        no = no->proximo; 
        }
        no_encadeado* novo_no = new no_encadeado(elemento);
        no->proximo = novo_no;
        novo_no->proximo = nullptr;
        this->tamanho++;
        int i = 0;
        while(i < tamanho){
            ordenar();
            i++;
        }
        return true;
    }
    return false;
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
// NOTE Necessário preservar a ordem relativa dos que restarem.
bool list::remover(int elemento) {
    int indice = obter_indice_de(elemento);
    if(indice == std::numeric_limits<int>::max()) return false;
    if(indice == 0) {
        no_encadeado* novo_primeiro = obter_no_em(indice + 1);
        this->primeiro = novo_primeiro;
        this->tamanho--;
        return true;
    } else {
        no_encadeado* anterior = obter_no_em(indice - 1);
        no_encadeado* remover = obter_no_em(indice);
        anterior->proximo = remover->proximo;
        this->tamanho--;
        return true;
    }
    return false;
}

// Determinar se "elemento" é um dos elementos ainda na coleção.
bool list::pertence(int elemento) {
    no_encadeado* no = this->primeiro;
    while(no->proximo != nullptr) {
        if(no->elemento == elemento) return true;
        no = no->proximo;
    }
    return false;
}


// --- Métodos de "Lista" ---
// Remover o elemento associado a "indice".
// Retornar indicativo de sucesso da remoção.
bool list::remover_de(unsigned int indice) {
    if(indice > this->tamanho) return false;
    if(indice == 0) {
        no_encadeado* novo_primeiro = obter_no_em(indice + 1);
        this->primeiro = novo_primeiro;
        this->tamanho--;
        return true;
    } else {
        no_encadeado* anterior = obter_no_em(indice - 1);
        no_encadeado* remover = obter_no_em(indice);
        anterior->proximo = remover->proximo;
        this->tamanho--;
        return true;
    }
    return false;
}

// Retornar o valor associado ao índice "indice".
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<int>::max()`
//      (forma de obter o maior valor representável).
int list::obter_elemento_em(unsigned int indice) {
    no_encadeado* no = obter_no_em(indice);
    if(indice > this->tamanho) return std::numeric_limits<int>::max();
    return no->elemento;
}

// Retornar o índice associado a "elemento".
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<unsigned int>::max()`
//      (forma de obter o maior valor representável).
int list::obter_indice_de(int elemento) {
    int indice = 0;
    no_encadeado* no = this->primeiro;

    while(no != nullptr) {
        if(no->elemento == elemento) {
            return indice;
        }else {
            indice++;
            no = no->proximo;
        }
    }
    return std::numeric_limits<int>::max();
}

void list::printar(list lista){
    no_encadeado* no = this->primeiro;
    int i = 0;
    while(i < tamanho){
        cout << "Elemento no indice(" << i << "):"<< no->elemento << endl;
        i++;
        no = no->proximo;
    }
}
// --- Métodos Auxiliares ---

// Construtor de um nó, onde a informação do próximo, no momento construção, é opcional
list::no_encadeado::no_encadeado(int elemento, no_encadeado* proximo) {
    this->elemento = elemento;
    this->proximo = proximo;
}

// Desejamos obter o próprio nó que esteja no índice informado.
// Deve retornar `nullptr` quando tal nó não existe.
// Auxilia processos que dependem de encontrar nós baseado em um índice.

list::no_encadeado* list::obter_no_em(int indice){
    int i = 0;
    no_encadeado* no = this->primeiro;
    while(i < indice){
        no = no->proximo;
        i++;
    }
    return no;
}

// Desejamos obter o próprio nó que veja **antes** de algum com o valor informado.
// (ou seja, `anterior.proximo.valor == valor`)
// Auxilia processos que dependem de encontrar nós baseado em um valor.
// Deve retornar `nullptr` quando tal nó não existe.
list::no_encadeado* list::obter_no_anterior_a(int valor){
    int indice = obter_indice_de(valor);
    if(indice == std::numeric_limits<unsigned int>::max()) return nullptr;
    no_encadeado* no_anterio = obter_no_em(indice - 1);
    return no_anterio;
}

void list::ordenar(){
    no_encadeado* no = this->primeiro;
    no_encadeado* no_dois = no->proximo;
    while(no->proximo != nullptr){
        if(no->elemento > no_dois->elemento){
            int aux = no->elemento;
            no->elemento = no_dois->elemento;
            no_dois->elemento = aux;            
        }
        no = no->proximo;
        no_dois = no->proximo;
    }
}

/*
void list::ordenar(list lista){
    no_encadeado* no = lista.primeiro;
    no_encadeado* no_dois = no->proximo;
    int i = 0;
    while(i < lista.tamanho){
        while(no->proximo != nullptr){
            if(no->elemento > no_dois->elemento){
                int aux = no->elemento;
                no->elemento = no_dois->elemento;
                no_dois->elemento = aux;            
            }
            no = no->proximo;
            no_dois = no->proximo;
        }
        i++;
    }
}


void list::ordenar(list lista){
    no_encadeado* no = lista.primeiro;
    no_encadeado* no_dois = no->proximo;
    for(int i = 0; i <= lista.tamanho; i++){
        while(no->proximo != nullptr){
            if(no->elemento > no_dois->elemento){
                int aux = no->elemento;
                no->elemento = no_dois->elemento;
                no_dois->elemento = aux;            
            }
        no = no->proximo;
        no_dois = no->proximo;
        }
    }    
}
void list::ordenar(int i){
    no_encadeado* no = this->primeiro;
    no_encadeado* no_dois = no->proximo;
    while(no->proximo != nullptr){
        if(no->elemento > no_dois->elemento){
            int aux = no->elemento;
            no->elemento = no_dois->elemento;
            no_dois->elemento = aux;            
        }
        no = no->proximo;
        no_dois = no->proximo;
    }
    if(i <= this->tamanho) ordenar(i++);
}
void list::ordenar(list lista){
    no_encadeado* no = this->primeiro;
    no_encadeado* no_dois = no->proximo;
    for(int i = 0; i <= lista.tamanho; i++){
        for(int j = 0; j <= lista.tamanho-i; j++){
            if(no->elemento > no_dois->elemento){
                int aux = no->elemento;
                no->elemento = no_dois->elemento;
                no_dois->elemento = aux;            
            }
            no = no->proximo;
            no_dois = no->proximo;
        }
    }    
}
void list::ordenar(list lista){
    no_encadeado* no = this->primeiro;
    no_encadeado* no_dois = no->proximo;
    while(no->proximo != nullptr){
        if(no->elemento > no_dois->elemento){
            int aux = no->elemento;
            no->elemento = no_dois->elemento;
            no_dois->elemento = aux;            
        }
        no = no->proximo;
        no_dois = no->proximo;
    }
}
list::no_encadeado* list::obter_no_anterior_a(int valor){
    int indice = obter_indice_de(valor);
    no_encadeado* no_anterio;
    if((no_anterio = obter_no_em(indice)) == nullptr){
        return nullptr;
    }else return no_anterio;
}
*/

/*
bool list::remover(int elemento) {
    int indice = obter_indice_de(elemento);
    if(indice == std::numeric_limits<int>::max()) return false;
    if(indice == 0) {
        no_encadeado* novo_primeiro = obter_no_em(indice + 1);
        this->primeiro = novo_primeiro;
        this->tamanho--;
        return true;
    } else {
        no_encadeado* anterior = obter_no_em(indice - 1);
        no_encadeado* remover = obter_no_em(indice);
        anterior->proximo = remover->proximo;
        this->tamanho--;
        return true;
    }
    return false;
}
*/