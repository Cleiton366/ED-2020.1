#include "fila_sequencial.hpp"
#include <iostream>
using namespace std;

typedef fila_sequencial fila;

int main(){

int capacidade;
int elemento;

cout << "Insira a capacidade da fila" << endl;
cin >> capacidade;
fila fila(capacidade);

while(1){
    int acao;
    cin >> acao;
    if(acao == 0) break;

    switch(acao){
        case 1:
            cout << "insira o elemento:" << endl;
            cin >> elemento;
            fila.enfilerar(elemento);
            cout << "elemento inserido na lista: " << elemento <<endl;
        break;
            
        case 2:
            fila.desenfilerar();
             cout << "elemento removido da lista " <<endl;
        break;

        case 3:
            fila.printar();
        break;
    }

}


    return 0;
}
