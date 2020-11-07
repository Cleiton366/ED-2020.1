#include <iostream>
#include <string>
#include "gerenciador.hpp"
#include <time.h>

using namespace std;

int main(){

bool menu = true, estado;
gerenciador a(100);
std::string s;
int indice = 0;
int data_prazo[3];
int filtro;

while(menu){
    a.limpar();
    indice = 0;
    cout << "Bem vindo ao Gerenciador de Tarefas" << endl;
    cout << "Escolha uma das opcoes abaixo" << endl;
    cout << "1 - Adicionar nova tarefa" << endl;
    cout << "2 - Remover tarefa existente" << endl;
    cout << "3 - Marcar uma tarefa como concluida" << endl;
    cout << "4 - Reabrir uma tarefa concluida" << endl;
    cout << "5 - Filtrar a exbicao de tarefas" << endl;
    cout << "6 - Visualizar todas as tarefas" << endl;
    cout << "7 - Ordenar tarefas manualmente" << endl;
    cout << "8 - Ordenar por prazo" << endl;
    cout << "9 - Ordenar por data de criacao" << endl;
    cout << "10 - Sair" << endl;
    int op;
    cin >> op;
    switch(op){
        case 1:
        a.limpar();
        cout << "Digite a descricao:" << endl;
        getline(cin,s);
        getline (cin,s);
        cout << "Digite o prazo da tarefa(DD/MM/AA):" << endl;
        for(int i = 0; i < 3; i++) cin >> data_prazo[i];
        if(a.adicionar_tarefa(s, false, data_prazo) == true){
            a.limpar();
            cout << "Tarefa adicionada" << endl;
        }else cout << "Algo deu errado :[" << endl;
        cout << "Aperte qualquer tecla para continuar" << endl;
        a.frezar_tela();
        break;

        case 2:
        a.limpar();
        filtro = a.get_filtro();
        a.filtrar(1);
        a.exibir(a);
        cout << "Digite o numero da tarefa que deseja remover" << endl;
        cin >> indice;
        if(a.remover_tarefa(indice) == true){
            a.limpar();
            cout << "Tarefa removida" << endl;
        }else cout << "Algo deu errado :[" << endl;
        a.filtrar(filtro);
        cout << "Aperte qualquer tecla para continuar" << endl;
        a.frezar_tela();
        break;

        case 3:
        a.limpar();
        filtro = a.get_filtro();
        a.filtrar(1);
        a.exibir(a);
        cout << "Qual tarefa foi concluida?" << endl;
        cin >> indice;
        if(a.marcar_concluido(indice) == true){
            a.limpar();
            cout << "Tarefa marcada como concluida!!" << endl;
        }else cout << "Algo deu errado :[" << endl;
        a.filtrar(filtro);
        cout << "Aperte qualquer tecla para continuar" << endl;
        a.frezar_tela();
        break;

        case 4:
        a.limpar();
        filtro = a.get_filtro();
        a.filtrar(1);
        a.exibir(a);
        cout << "Quer reabrir qual tarefa?" << endl;
        cin >> indice;
        if(a.reabrir_tarefa(indice) == true){
            a.limpar();
            cout << "Tarefa reaberta com suscesso!!" << endl;
        }else cout << "Algo deu errado :[" << endl;
        a.filtrar(filtro);
        cout << "Aperte qualquer tecla para continuar" << endl;
        a.frezar_tela();
        break;

        case 5:
        a.limpar();
        cout << "Como deseja ver suas tarefas?" << endl;
        cout << "1 - Ver todas as tarefas" << endl;
        cout << "2 - Somente tarefas nao concluidas" << endl;
        cout << "3 -  Somente tarefas concluidas" << endl;
        cin >> indice;
        a.filtrar(indice);
        cout << "Configuracao de filtro atualizado" << endl;
        cout << "Aperte qualquer tecla para continuar" << endl;
        a.frezar_tela();
        break;
        case 6:
        a.limpar();
        a.exibir(a);
        cout << endl << "Aperte qualquer tecla para continuar" << endl;
        a.frezar_tela();
        break;
        case 7:
        a.limpar();
        cout << "Como deseja ordenar?" << endl;
        cout << "1 - Troca uma tarefa por outra" << endl;
        cout << "2 - Subir uma tarefa na tabela de tarefas" << endl;
        cout << "3 - Descer uma tarefa na tabela de tarefas" << endl;
        int ordem;
        int outro;
        filtro = a.get_filtro();
        a.filtrar(1);
        cin >> ordem;
        if(ordem == 1){
            a.limpar();
            a.exibir(a);
            cout << "Qual tarefa quer trocar?" << endl;
            cin >> indice;
            cout << "Quer trocar por qual tarefa?" << endl;
            cin >> outro;
            a.ordenar_manual(indice, outro, ordem);
            a.limpar();
            cout << "Tarefas trocadas!!" << endl;
            cout << endl << "Aperte qualquer tecla para continuar" << endl;
            a.frezar_tela();
        }else if (ordem == 2){
            a.limpar();
            a.exibir(a);
            cout << "Qual tarefa quer subir na tabela?" << endl;
            cin >> indice;
            if(indice == 0){
                a.limpar();
                cout << "Essa tarefa ja esta no topo D:!!";
                cout << endl << "Aperte qualquer tecla para continuar" << endl;
                a.frezar_tela();
                break;
            }
            a.ordenar_manual(indice, outro, ordem);
            a.limpar();
            cout << "Tarefas foi pra cima!!" << endl;
            cout << endl << "Aperte qualquer tecla para continuar" << endl;
            a.frezar_tela();
        }else if(ordem == 3){
            a.limpar();
            a.exibir(a);
            cout << "Qual tarefa quer descer na tabela?" << endl;
            cin >> indice;
            int qtd = a.get_qtd();
            if(indice == qtd-1){
                a.limpar();
                cout << "Essa tarefa ja esta la em baixo D:!!";
                cout << endl << "Aperte qualquer tecla para continuar" << endl;
                a.frezar_tela();
                break;
            }
            a.ordenar_manual(indice, outro, ordem);
            a.limpar();
            cout << "Tarefas foi pra baixo!!" << endl;
            cout << endl << "Aperte qualquer tecla para continuar" << endl;
            a.frezar_tela();
        }else{
            a.limpar();
            cout << "Opcao invalida, vou te levar para o menu!";
            cout << endl << "Aperte qualquer tecla para continuar" << endl;
            a.frezar_tela();
            break;
        }
        a.filtrar(filtro);
        break;

        case 8:
        a.limpar();
        a.ordenar_prazo();
        cout << "As tarefas estao ordenadas pelo prazo!" << endl;
        cout << "Aperte qualquer tecla para continuar" << endl;
        a.frezar_tela();
        break;
        
        case 9:
        a.limpar();
        a.ordenar_criacao();
        cout << "As tarefas estao ordenadas pela data de criacao!" << endl;
        cout << endl << "Aperte qualquer tecla para continuar" << endl;
        a.frezar_tela();
        break;

        case 10:
        menu = false;
        break;
    }

}
    return 0;
}
