#include "pilha_encadeada.hpp"
#include <iostream>
using namespace std;

typedef pilha_encadeada pilha;
pilha::pilha_encadeada(){this->topo = nullptr;}

pilha::no_encadeado::no_encadeado(int elemento, no_encadeado* proximo){
    this->elemento = elemento;
    this->proximo = proximo;
}


bool pilha::empilhar(int elemento){
    if(this->topo == nullptr){
        no_encadeado* no = new no_encadeado(elemento, nullptr);
        this->topo = no;
        
        return true;
    }else {
        no_encadeado* no = new no_encadeado(elemento, this->topo);
        this->topo = no;
        return true;
    }
}

bool pilha::desempilhar(){
    if(this->topo == nullptr) return false;
    this->topo = topo->proximo;
    return true;   
}

void pilha::printar(){

    no_encadeado* no = this->topo;

    while(no){
        cout << "Elemento: " << no->elemento << endl;
        no = no->proximo;
    }
}