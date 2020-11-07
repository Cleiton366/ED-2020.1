#include "pilha_encadeada.hpp"
#include <iostream>
using namespace std;
typedef pilha_encadeada pilha;

int main (){

    pilha p;

    while(1){
        int acao;
        int elemento;
        cin >> acao;
        if(acao == 0) break;

        switch(acao){
            case 1:
                cout << "insira o elemento: " << endl;
                cin >> elemento;
                if(p.empilhar(elemento) == true) {
                    cout << "empilhou!" << endl;
                }else cout << "algo deu errado" << endl;
            break;

            case 2:
                if(p.desempilhar() == true){
                    cout << "desempilhou!" << endl;
                }else cout << "pilha vazia" << endl;
            break;
            
            case 3:
                p.printar();
            break;
        }
    }

    return 0;
}