#include "ordered_list.hpp"

#include <iostream>
#include <limits>

using namespace std;

int main() {    
    list l;
    
    while(1){

        int acao = 0;
        int elemento = 0;
        int indice = 0;
        cin >> acao;

        switch(acao){
            case 0:
                l.ordenar();
                break;
            case 1:
                l.printar(l);
            break;
            
            case 2:
                cout << "Insira o elemento:" << endl;
                cin >> elemento;
                if((l.inserir(elemento)) == true){
                    cout << "Inseriu" << endl;
                }else cout << "Nao inseriu" << endl;
            break;

            case 3:
                cout << "Insira o elemento:" << endl;
                cin >> elemento;
                if(l.remover(elemento) == true){
                    cout << "Removeu";
                }else cout << "N removeu";
            break;

            case 4:
                cout << "Insira o elemento:" << endl;    
                cin >> elemento;
                if(l.pertence(elemento) == true){
                    cout << "Elemento existe" << endl;
                }else cout << "N existe" << endl;
                break;
            case 6:
                cout << "Insira o indice:" << endl;
                cin >> indice;
                if((l.remover_de(indice)) == true){
                     cout << "Removeu";
                }else cout << "N removeu";
                break;
            case 7:
                cout << "Insira o indice:" << endl;
                cin >> indice;
                elemento = l.obter_elemento_em(indice);
                if(elemento == std::numeric_limits<int>::max()){
                    cout << "Elemento inexistente";
                }else cout << "Elemento no indice(" << indice << "):" << elemento << endl;
                break;    
            case 8:
                cout << "Insira o elemento:" << endl;
                cin >> elemento;
                indice = l.obter_indice_de(elemento);
                if(indice == std::numeric_limits<int>::max()){
                    cout << "Elemento n existe" << endl;
                }else cout << indice << endl;
                break;    
        }
    }
    
    return 0;
}