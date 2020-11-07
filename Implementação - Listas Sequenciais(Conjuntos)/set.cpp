#include "set.hpp"
#include <limits>
#include <iostream>
using namespace std;

// Construir lista vazia, mas com capacidade máxima informada.
set::set(unsigned int capacidade) {
    vetor = new int[capacidade];
    tamanho = 0;
    this->capacidade = capacidade;
}

// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção.
// Retornar indicativo de sucesso da inserção.
// NOTE Deve aumentar a capacidade caso necessário.
// NOTE Observe que aumentar em apenas uma unidade não nos alivia da pressão que tínhamos antes...
bool set::inserir(int elemento) {
    if(tamanho == capacidade) return false;
    if(tamanho <= capacidade) {
        this->vetor[tamanho] = elemento;
        this->tamanho++;
        ordenar();
        return true;
    }else return false;
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
// NOTE Necessário preservar a ordem relativa dos que restarem.
bool set::remover(int elemento) {
    if(this->tamanho == 0) return false;
    int k = obter_indice_de(elemento);
    if(k == std::numeric_limits<int>::max()) return false;
    if(k >= 0){
        int j = k;
        while(j < tamanho){
            this->vetor[j] = this->vetor[j+1];
            j++;
        }
        this->tamanho--;
    }
    return true;
}

// Determinar se "elemento" é um dos elementos ainda na coleção.
bool set::pertence(int elemento) const {
    if(tamanho == 0) return false;   
    int i = 0;
    while(i < this->tamanho){
        if(this->vetor[i] == elemento) return true;
        i++;
    }
    return false;
}


// --- Métodos de "Conjunto" ---

// Tornar o próprio conjunto (`this`) o resultado de sua união com o outro informado.
bool set::uniao_com(set const &conjunto) {
    if(conjunto.capacidade > this->capacidade) return false;
    for(int i = 0; i < conjunto.tamanho; i++){
        this->inserir(conjunto.vetor[i]);
    }
    for(int i = 0; i < this->tamanho; i++) if(this->vetor[i] == this->vetor[i+1]) this->remover(vetor[i]);
    return true;
}

// Tornar o próprio conjunto (`this`) o resultado de sua intersecção com o outro informado.
void set::intersecao_com(set const &conjunto) {
   int tam = tamanho, i = 0;
   while(i < tam){
        if(conjunto.pertence(this->vetor[i]) == false) this->remover(vetor[i]);
        i++;
   }
}
// Testar se este conjunto (`this`) está contido no outro informado.
bool set::esta_contido_em(set const &conjunto) const {
    if(conjunto.tamanho < tamanho) return false;
    int k = 0;
    for(int i = 0; i < tamanho; i++){
        if(conjunto.pertence(vetor[i]) == true){
            k++;
        }
    }
    if(k == this->tamanho){
        return true;
    }else return false;
}

int set::obter_indice_de(int elemento) {
    if(tamanho == 0) return std::numeric_limits<int>::max();
    int i = 0;
    while(i < tamanho){
        if(vetor[i] == elemento) return i;
        i++;
    }
    return std::numeric_limits<int>::max();
}

int set::ordenar(){

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho-i; j++){
            if(vetor[j] > vetor[j+1]){
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void set::printar(){

    for(int i = 0; i < this->tamanho; i++){
        cout << "Elemento no indice("<< i+1 << "):" << this->vetor[i] << endl; 
    }
}


/*void set::uniao_com(set const &conjunto) {
    int nova_capacidade = this->capacidade + conjunto.capacidade;
    int indice = this->capacidade;
    int indice_conjunto = 0;
    this->vetor =  new int[nova_capacidade];
    this->capacidade = nova_capacidade;

    while(indice < this->capacidade){
        this->vetor[indice] = conjunto.vetor[indice_conjunto];
        indice_conjunto++;
        indice++;
        this->tamanho++;
    }
}*/