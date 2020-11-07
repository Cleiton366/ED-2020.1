#include "vector.hpp"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    unsigned int capacidade;
    cout << "insira capacidade do vetor";
    cin >> capacidade;
    
    vector v(capacidade);
    
    while (1) {
        int acao;
        int elemento;
        unsigned int indice;
        
        cout <<"insira a opcao" << endl;
        cin >> acao;
        
        switch(acao) {
            case 0://imprimi todos os elementos da lista
            v.printar(v);
            break;
            case 1://inserir elemento
            cin >> elemento;
            if(v.inserir(elemento) == true) {
                cout << "Inseriu!" << endl;
            }else cout << "N Inseriu"<< endl;
             break;

            case 2://remover elemento
            cin >> elemento;
            if(v.remover(elemento) == true){
                cout << "Removeu" << endl;
            }else cout << "N Removeu" << endl;
            break;

            case 3://elemento pertence ou n a lista
            cin >> elemento;
            if(v.pertence(elemento) == true){
                cout << "Elemento existe na lista" << endl;
            }else cout << "Elemento nao existe na lista" << endl;
            break;

            case 4://inserir elemento em um indice 
            cin >> indice >> elemento;
            if(v.inserir_em(indice, elemento) == true){
                cout << "Inseriu!" << endl;
            }else cout << "N Inseriu"<< endl;
            break;

            case 5://remover elemento de um indice
            cin >> indice;
            if(v.remover_de(indice) == true){
                cout << "Removeu" << endl;
            }else cout << "N Removeu" << endl;
            break;

            case 6://obter elemento em indice
            cin >> indice;
            int k = v.obter_elemento_em(indice);
            if(k == std::numeric_limits<int>::max()){
                cout << "elemento nao encontrado" << endl;
            }else cout << "elemento:" << k << endl;
            break;
        }
    }
   
    return 0;
}