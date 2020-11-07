#include "linked_set.hpp"
#include <iostream>
#include <limits>

using namespace std;

int main() {
    int capacidade_v, capacidade_u;
    int comandos;
    linked_set a;
    linked_set b;

    a.inserir(1);
    a.inserir(5);
    a.inserir(7);
    a.inserir(13);
    a.inserir(45);
    a.inserir(9);
    a.inserir(23);
    a.inserir(253);
    a.inserir(273);
    a.inserir(123);

    b.inserir(1);
    b.inserir(2);
    b.inserir(5);
    b.inserir(7);
    b.inserir(9);

    // a.uniao_com(b); //funcionando
    // a.esta_contido_em(b); //funcionando
    // a.intersecao_com(b); //funcionando
    // cout << a.esta_contido_em(b); //funcionando
    a.printar(a);
    /*
    cin >> capacidade_v >> capacidade_u >> comandos;
    
    linked_set v(capacidade_v);
    linked_set u(capacidade_u);
    
    while (comandos-- > 0) {
        char acao, conjunto;
        int elemento;
        linked_set *alvo, *outro;
        
        cin >> acao >> conjunto;
        
        if(conjunto == 'u') {
            alvo  = &u;
            outro = &v;
        } else {
            alvo  = &v;
            outro = &u;
        }
        
        switch(acao) {
            case 'i':
                cin >> elemento;
                cout << alvo->inserir(elemento) << endl;
                break;
            case 'r':
                cin >> elemento;
                cout << alvo->remover(elemento) << endl;
                break;
            case 'p':
                cin >> elemento;
                cout << alvo->pertence(elemento) << endl;
                break;
            case 't':
                cout << alvo->obter_tamanho() << endl;
                break;
            case 'c':
                cout << (alvo->obter_capacidade() >= alvo->obter_tamanho()) << endl;
                break;
            case 'U':
                alvo->uniao_com(*outro);
                cout << "ok" << endl;
                break;
            case 'I':
                alvo->intersecao_com(*outro);
                cout << "ok" << endl;
                break;
            case 'S':    
                cout << alvo->esta_contido_em(*outro) << endl;
                break;
        }
    }*/
    
    return 0;
}