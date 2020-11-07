#include "fila_sequencial.hpp"
#include <iostream>
using namespace std;

typedef fila_sequencial fila;

fila::fila_sequencial(int capacidade){
    fila = new int[capacidade];
    tamanho = 0;
    this->capacidade = capacidade;
    this->inicio = 0;
}

bool fila::enfilerar(int elemento){
    if(tamanho == capacidade) return false;
    int fim = (this->inicio + this->tamanho) % capacidade;
    this->fila[fim] = elemento;
    this->tamanho++;
    return true;
}

bool fila::desenfilerar(){
    if(this->tamanho > 0){
      this->inicio = (this->inicio + 1) % this->capacidade;
      this->tamanho--;
      return true;  
    }
    return false;
}

void fila::printar(){
    int i = this->inicio, j = 0;

    while(j < tamanho){
        cout << "elemento: " <<  this->fila[i] << " no indice:"<< i << endl;
        i = (i + 1) % this->capacidade;
        j++;
    }
}
