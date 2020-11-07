#include "fila.hpp"
#include <iostream>
#include <limits>

using namespace std;

int main() {    
    fila l;
    
    while(1){

        int acao = 0;
        int elemento = 0;
        int indice = 0;
        cin >> acao;

        if(acao == 0) break;

        switch(acao){
            case 1:
                l.printar(l);
            break;
            
            case 2:
                cout << "Insira o elemento:" << endl;
                cin >> elemento;
                l.enfilerar(elemento);
                cout << "elemento inserido na fila: " << elemento << endl;
            break;

            case 3:
                l.desenfilerar();
                cout << "elemento removido da fila " << endl;
            break;
        }
    }
    
    return 0;
}