#include "pilha_sequencial.hpp"
#include <iostream>
using namespace std;

typedef pilha_sequencial pilha;

pilha::pilha_sequencial(int capacidade){
    this->pilha = new int[capacidade];
    this->capacidade = capacidade;
    this->topo = -1;
}

bool pilha::empilhar(int elemento){
    if(this->topo+1 == this->capacidade) return false;

    this->pilha[topo+1] = elemento;
    this->topo++;
    cout << topo << endl;
    return true;
}

bool pilha::desempilhar(){
    if(this->topo >= 0){
        this->topo--;
        return true;
    }else return false;

}

void pilha::printar(){

    int i = 0;
    while(i < this->topo+1){
        cout << "Elemento no indice("<< i << "):" << this->pilha[i] << endl;
        i++;
    }
}