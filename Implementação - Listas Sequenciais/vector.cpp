#include "vector.hpp"
#include <limits>
#include <iostream>

using namespace std;

// Construir lista vazia, mas com capacidade máxima informada.
vector::vector(unsigned int capacidade) {
    vetor = new int[capacidade];
    tamanho = 0;
    this->capacidade = capacidade;
}

// Construir lista com "tamanho" cópias do valor "inicial".
vector::vector(unsigned int tamanho, int inicial) {
    vetor = new int[tamanho];
    capacidade = tamanho;
    this->tamanho = tamanho;

    for(unsigned int i = 0; i < tamanho; i++) {
        vetor[i] = inicial;
    }
}


// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção. Sempre deve executar a inserção.
// FIXME Fazer realocação quando não houver espaço.
// NOTE  Observe que aumentar em apenas uma unidade não nos alivia da pressão que tínhamos antes...
bool vector::inserir(int elemento) {
    // TODO Reorganizar o código
    if(tamanho == capacidade) return false;
    if(tamanho <= capacidade) {
        tamanho++;
        vetor[tamanho] = elemento;
        return true;
    }
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
// NOTE Necessário preservar a ordem relativa dos que restarem.
bool vector::remover(int elemento) {
    if(tamanho == 0) return false;
    int k = obter_indice_de(elemento);
    if(k == std::numeric_limits<int>::max()) return false;
    if(k >= 0){
        int j = k;
        while(j < tamanho){
            vetor[j] = vetor[j+1];
            j++;
        }
        tamanho--;
    }
    return true;
}

// Determinar se "elemento" é um dos elementos ainda na coleção.
bool vector::pertence(int elemento) {
    if(tamanho == 0) return false;   
    int i = 0;
    while(i <= tamanho){
        if(vetor[i] == elemento) return true;
        i++;
    }
    return false;
}


// --- Métodos de "Lista" ---

// Inserir "elemento" na lista de forma que ele passe a constar no índice "indice".
// NOTE Necessário preservar a ordem relativa dos demais elementos.
bool vector::inserir_em(unsigned int indice, int elemento) {
    if(tamanho == capacidade) return false;
    
    int k = tamanho + 1;
    while(indice < k){
        vetor[k] = vetor[k-1];
        k--;
    }

    vetor[k] = elemento;
    tamanho++;
    return true;
}

// Remover o elemento associado a "indice".
// Retornar indicativo de sucesso da remoção.
bool vector::remover_de(unsigned int indice) {
    if(tamanho == 0) return false;

    int i = indice;
    tamanho--;
    while(i <= tamanho){
        vetor[i] = vetor[i+1];
        i++;
    }
    return true;
}

// Retornar o valor associado ao índice "indice".
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<int>::max()`
//      (forma de obter o maior valor representável).
int vector::obter_elemento_em(unsigned int indice) {
    if(tamanho == 0) return std::numeric_limits<int>::max();
    int i = indice;
    while(i <= tamanho){
        if(vetor[i] == indice) return vetor[i];
        i++;
    }
    return std::numeric_limits<int>::max();
}

// Retornar o índice associado a "elemento".
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<unsigned int>::max()`
//      (forma de obter o maior valor representável).
unsigned int vector::obter_indice_de(int elemento) {
    if(tamanho == 0) return std::numeric_limits<int>::max();
    int i = 0;
    while(i <= tamanho){
        if(vetor[i] == elemento) return i;
        i++;
    }
    return std::numeric_limits<int>::max();
}

void vector::printar(vector vetor){
    int i = 1;
    while(i <= vetor.tamanho){
        cout << "Elemento no indice("<< i << "):" << vetor.vetor[i] << endl;
        i++; 
    }
}
