#include "pilha_sequencial.hpp"
#include <iostream>
typedef pilha_sequencial pilha;

using namespace std;

int main(){

    int capacidade;
    cout << "insira capacidade da pilha:" << endl;
    cin >> capacidade;

    pilha p(capacidade);

    while(1){
        int acao;
        int elemento;

        cin >> acao;
        if(acao == 0) break;

        switch(acao){
            case 1:
                cout << "insira um elemento:" << endl;
                cin >> elemento;
                if(p.empilhar(elemento) == true){
                    cout << "empilhou!" << endl;
                }else cout << "pilha cheia" << endl;
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