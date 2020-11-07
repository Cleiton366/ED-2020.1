#include "fila.hpp"
#include <iostream>
#include <limits.h>
using namespace std;

fila::fila(){
    this->primeiro = nullptr;
    this->tamanho = 0;
}
fila::no_encadeado::no_encadeado(int elemento, no_encadeado* proximo) {
    this->elemento = elemento;
    this->proximo = proximo;
}

void fila::enfilerar(int elemento){
    if(this->primeiro == nullptr){
        no_encadeado* novo_no = new no_encadeado(elemento, nullptr);
        this->primeiro = novo_no;
        this->ultimo = novo_no;
        this->tamanho++;
    }else{
        no_encadeado* ultimo = this->ultimo;
        no_encadeado* novo_no = new no_encadeado(elemento, nullptr);
        ultimo->proximo = novo_no;
        this->ultimo = novo_no;
        this->tamanho++;
    }
}

void fila::desenfilerar(){
    no_encadeado* no = this->primeiro;
    this->primeiro = no->proximo;
}

bool fila::pertence(int elemento) {
    no_encadeado* no = this->primeiro;
    while(no->proximo != nullptr) {
        if(no->elemento == elemento) return true;
        no = no->proximo;
    }
    return false;
}

void fila::printar(fila lista){
    no_encadeado* no = this->primeiro;
    int i = 0;
    while(no){
        cout << "Elemento no indice(" << i << "):"<< no->elemento << endl;
        i++;
        no = no->proximo;
    }
}
