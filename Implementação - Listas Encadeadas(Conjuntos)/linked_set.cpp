#include "linked_set.hpp"
#include <limits>
#include <iostream>
using namespace std;

// Construir lista vazia, mas com capacidade máxima informada.
linked_set::linked_set() {
    this->primeiro = nullptr;
    this->tamanho = 0;
}

// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção.
// Retornar indicativo de sucesso da inserção.
// NOTE Deve aumentar a capacidade caso necessário.
// NOTE Observe que aumentar em apenas uma unidade não nos alivia da pressão que tínhamos antes...
bool linked_set::inserir(int elemento) {
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
bool linked_set::remover(int elemento) {
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
bool linked_set::pertence(int elemento) const {
    no_encadeado* no = this->primeiro;
    int i = 0;
    while(i < this->tamanho) {
        if(no->elemento == elemento) return true;
        no = no->proximo;
        i++;
    }
    return false;
}


// --- Métodos de "Conjunto" ---

// Tornar o próprio conjunto (`this`) o resultado de sua união com o outro informado.
void linked_set::uniao_com(linked_set &conjunto) {
    no_encadeado* no = this->primeiro;
    no_encadeado* no_dois = no->proximo;
    no_encadeado* no_outro = conjunto.primeiro;
    int i = 0;
    while(i < conjunto.tamanho){
        inserir(no_outro->elemento);
        no_outro = no_outro->proximo;
        i++;
    }
    i = 0;
    while(i < this-> tamanho){
        if(no->elemento == no_dois->elemento) remover(no->elemento);
        i++;
        no = no->proximo;
        no_dois = no->proximo;
    }
}

// Tornar o próprio conjunto (`this`) o resultado de sua intersecção com o outro informado.
void linked_set::intersecao_com(linked_set &conjunto) {
    no_encadeado* no = this->primeiro;
    int i = 0;
    int tam = tamanho;
    while(i < tam){
        if(conjunto.pertence(no->elemento) == false) remover(no->elemento);
        i++;
        no = no->proximo;
    }
}

// Testar se este conjunto (`this`) está contido no outro informado.
bool linked_set::esta_contido_em(linked_set &conjunto) {
    if(conjunto.tamanho < tamanho) return false;
    no_encadeado* no = this->primeiro;
    int k = 0;
    while(no != nullptr){
       if(conjunto.pertence(no->elemento) == true) k++;
       no = no->proximo;
    }
    if(k == tamanho){
        return true;
    }else return false;
}
int linked_set::e_igual(int i, int elemento){
    no_encadeado* no = this->primeiro;
    while(no->proximo != nullptr){
        if(no->elemento == elemento) return 1;
    }
    return 0;
}

// --- Métodos Auxiliares ---

int linked_set::obter_indice_de(int elemento) {
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

// Construtor de um nó, onde a informação do próximo, no momento construção, é opcional
linked_set::no_encadeado::no_encadeado(int valor, no_encadeado* proximo) {
    this->elemento = valor;
    this->proximo = proximo;
}

// Desejamos obter o próprio nó que esteja no índice informado.
// Deve retornar `nullptr` quando tal nó não existe.
// Auxilia processos que dependem de encontrar nós baseado em um índice.
linked_set::no_encadeado* linked_set::obter_no_em(int indice) {
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
linked_set::no_encadeado* linked_set::obter_no_anterior_a(int valor) {
    int indice = obter_indice_de(valor);
    if(indice == std::numeric_limits<unsigned int>::max()) return nullptr;
    no_encadeado* no_anterio = obter_no_em(indice - 1);
    return no_anterio;
}

void linked_set::ordenar(){
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

void linked_set::printar(linked_set lista){
    no_encadeado* no = this->primeiro;
    int i = 0;
    while(i < tamanho){
        cout << "Elemento no indice(" << i << "):"<< no->elemento << endl;
        i++;
        no = no->proximo;
    }
}
