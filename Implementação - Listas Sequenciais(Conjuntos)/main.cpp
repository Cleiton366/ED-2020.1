#include "set.hpp"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    unsigned int capacidade_a, capacidade_b;
    int elemento;
    
    cin >> capacidade_a >> capacidade_b;
    set a(capacidade_a);
    set b(capacidade_b);

    set *alvo, *outro;

    cout << "digite o conjunto a" << endl;
    for(int i = 0; i < capacidade_a; i++){
        cin >> elemento;
        a.inserir(elemento);
    }
    cout << "digite o conjunto b" << endl;
    for(int i = 0; i < capacidade_b; i++){
        cin >> elemento;
        b.inserir(elemento);
    }
    a.printar();
    bool menu1;
    while(menu1){
        cout <<"qual conjunto e o alvo?" << endl;
        cout <<"1 - conjunto A alvo, conjunto B outro" << endl;
        cout <<"2 - conjunto B alvo, conjunto A outro" << endl;
        int op;
        cin >> op;

        if(op == 1){
            alvo = &a;
            outro = &b;
            menu1 = false;
        }else if(op == 2){
            alvo = &b;
            outro = &a;
            menu1 = false;
        }else cout << "opcao invalida" << endl;
    }
    bool menu2;
    while(menu2){

        int op;
        cin >> op;
        cout << "1 - Remover do conjunto alvo" << endl;
        cout << "2 - Elemento pertence ao conjunto alvo" << endl;
        cout << "3 - Uniao de alvo e outro" << endl;
        cout << "4 - Intersecao alvo e outro" << endl;
        cout << "5 - Alvo esta contino em outro" << endl;
        cout << "6 - Printar alvo" << endl;
        cout << "7 - Sair" << endl;
        switch(op){
            case 1:
                cin >> elemento;
                if((alvo->remover(elemento)) == true){
                    cout << "removeu" << endl;
                }else cout << "nao removeu" << endl;
                break;
            case 2:
                cin >> elemento;
                if((alvo->pertence(elemento)) == true){
                    cout << "elemento esta contido em alvo" << endl;
                }else cout << "nao esta contido" << endl;
                break;
            case 3:
                if((alvo->uniao_com(*outro)) == true){
                    cout << "uniao feita" << endl;
                }else cout << "erro" << endl;
                break;
            

        }
    }
   
    return 0;
}