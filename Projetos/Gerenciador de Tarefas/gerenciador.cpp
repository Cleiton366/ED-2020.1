#include "gerenciador.hpp"
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

//construtores
gerenciador::gerenciador(int tamanho){
    this->vetor = new tarefa[tamanho];
    this->tamanho = tamanho;
    qtd = 0;
    filtro = 1;
}

gerenciador::tarefa::tarefa(){}

gerenciador::tarefa::tarefa(std::string descricao, bool estado, int data_criacao[3], int data_prazo[3]){
    this->descricao = descricao;
    this->estado = estado;
    for(int i = 0; i < 3; i++){
        this->data_criacao[i] = data_criacao[i];
        this->data_prazo[i] = data_prazo[i];
    }
}

bool gerenciador::adicionar_tarefa(std::string descricao, bool estado, int data_prazo[3]){
    
    //tarefa* t = new tarefa(descricao, estado, data_criacao, data_prazo);
    if(qtd == tamanho) return false;
    this->vetor[qtd].descricao = descricao;
    this->vetor[qtd].estado = estado;
    preencher_datas(data_prazo);
    this->qtd++;
    return true;
}

bool gerenciador::remover_tarefa(int indice){
    if(qtd == 0) return false;
    if(indice > qtd) return false;
    while(indice < qtd){
        vetor[indice] = vetor[indice+1];
        indice++;
    }
    qtd--;
    return true;
}

bool gerenciador::marcar_concluido(int indice){
    int i = 0;
    while(i < qtd){
        if(i == indice){
            vetor[i].estado = true;
        }
        i++;
    }
    return true;
}

bool gerenciador::reabrir_tarefa(int indice){
    int i = 0;
    while(i < qtd){
        if(i == indice){
            vetor[i].estado = false;
        }
        i++;
    }
    return true;
}

void gerenciador::filtrar(int op){
    this->filtro = op;  
}

void gerenciador::exibir(gerenciador a){
    //op = 1 exibir todas / op = 2 exibir abertas / op = 3 exibir concluidas
    int indice = 0;
    if(this->filtro == 1){
        cout << "Todas as tarefas:" << endl;
        for(int i = 0; i < qtd; i++){
            cout << "Tarefa numero:" << indice++ << endl;
            cout <<"Descricao = "<< vetor[i].descricao << endl;
            if(vetor[i].estado == true){
                cout << "Estado = Concluida." << endl;
            }else cout << "Estado = Pendente." << endl;
            cout << "Criado em = ";
            for(int k = 0; k < 3; k++) cout <<vetor[i].data_criacao[k] << ".";
            cout << endl;
            cout << "Prazo ate = ";
            for(int k = 0; k < 3; k++) cout <<vetor[i].data_prazo[k] << ".";
            cout << endl << endl;
        }
    }else if(this->filtro == 2){
        cout << "Tarefas pendentes:" << endl;
        for(int i = 0; i < qtd; i++){
            if(vetor[i].estado == false){
                cout << "Tarefa numero:" << indice++ << endl;
                cout <<"Descricao = "<< vetor[i].descricao << endl;
                cout << "Estado = Pendente." << endl;
                cout << "Criado em = ";
                for(int k = 0; k < 3; k++) cout <<vetor[i].data_criacao[k] << ".";
                cout << endl;
                cout << "Prazo ate = ";
                for(int k = 0; k < 3; k++) cout <<vetor[i].data_prazo[k] << ".";
                cout << endl << endl;
            }
        }
    } else if(this->filtro == 3){
        cout << "Tarefas concluidas:" << endl;
        for(int i = 0; i < qtd; i++){
            if(vetor[i].estado == true){
                cout << "Tarefa numero:" << indice++ << endl;
                cout <<"Descricao = "<< vetor[i].descricao << endl;
                cout << "Estado = Conluida." << endl;
                 cout << "Criado em = ";
                for(int k = 0; k < 3; k++) cout <<vetor[i].data_criacao[k] << ".";
                cout << endl;
                cout << "Prazo ate = ";
                for(int k = 0; k < 3; k++) cout <<vetor[i].data_prazo[k] << ".";
                cout << endl << endl;
            }
        }
    }

}

void gerenciador::preencher_datas(int data_prazo[3]){
    struct tm* data_criacao;
    time_t data;
    time(&data);
    data_criacao = localtime(&data);
    this->vetor[qtd].data_criacao[0] = data_criacao->tm_mday;
    this->vetor[qtd].data_criacao[1] = data_criacao->tm_mon+1;
    this->vetor[qtd].data_criacao[2] = data_criacao->tm_year+1900;

    this->vetor[qtd].data_prazo[0] = data_prazo[0];
    this->vetor[qtd].data_prazo[1] = data_prazo[1];
    this->vetor[qtd].data_prazo[2] = data_prazo[2];
    
}
int dataint(int num, int vetor[3]){
    num = 0;
    for (int i = 0; i < 3; i++) {
        num *= 10;
        num += vetor[i];
    }
    return num;
}

bool gerenciador::adicionar_tarefa_em(int indice, tarefa* t){
    if(qtd == tamanho) return false;
    
    int k = qtd + 1;
    while(indice < k){
        vetor[k] = vetor[k-1];
        k--;
    }

    vetor[k].descricao = t->descricao;
    vetor[k].estado = t->estado;
    copiar_datas(t, k);
    qtd++;
    return true;
}

void gerenciador::copiar_datas(tarefa* t, int indice){
    for(int i = 0; i < 3; i++){
        vetor[indice].data_criacao[i] = t->data_criacao[i];
        vetor[indice].data_prazo[i] = t->data_prazo[i];
    }
}

void gerenciador::ordenar_criacao(){

    for(int i = 0; i < qtd; i++){
        for(int j = 0; j < qtd-i; j++){
            if(vetor[j].data_criacao[1] < vetor[j+1].data_criacao[1]
            || vetor[j].data_criacao[1] < vetor[j+1].data_criacao[1] 
            && vetor[j].data_criacao[0] < vetor[j+1].data_criacao[0]){
                tarefa* aux = new tarefa(vetor[j]);
                vetor[j] = vetor[j+1];
                remover_tarefa(j+1);
                adicionar_tarefa_em(j+1, aux);
            }
        }
    }
}

void gerenciador::ordenar_prazo(){
    for(int i = 0; i < qtd; i++){
        for(int j = 0; j < qtd-i; j++){
            if(vetor[j].data_prazo[1] < vetor[j+1].data_prazo[1]
            || vetor[j].data_prazo[1] < vetor[j+1].data_prazo[1] 
            && vetor[j].data_prazo[0] < vetor[j+1].data_prazo[0]){
                tarefa* aux = new tarefa(vetor[j]);
                vetor[j] = vetor[j+1];
                remover_tarefa(j+1);
                adicionar_tarefa_em(j+1, aux);
            }
        }
    }
}

void gerenciador::ordenar_manual(int indice_alvo, int outro, int op){
//op = 1 trocar de posição com outra tarefa informada
//op = 2 subir uma quantidade de posições informada
//op = 3 descer uma quantidade de posições informada
    if(op == 1){
        tarefa* aux = new tarefa(vetor[indice_alvo]);
        vetor[indice_alvo] = vetor[outro];
        remover_tarefa(outro);
        adicionar_tarefa_em(outro, aux);
    }else if(op == 2){
        tarefa* aux = new tarefa(vetor[indice_alvo]);
        vetor[indice_alvo] = vetor[indice_alvo-1];
        remover_tarefa(indice_alvo);
        adicionar_tarefa_em(indice_alvo-1, aux);
    }else if(op == 3){
        tarefa* aux = new tarefa(vetor[indice_alvo]);
        vetor[indice_alvo] = vetor[indice_alvo+1];
        remover_tarefa(indice_alvo);
        adicionar_tarefa_em(indice_alvo + 1, aux);
    }

}

void gerenciador::limpar(){
    system("CLS");
}

void gerenciador::frezar_tela(){
    std::string s;
    getline(cin,s);
    getline(cin,s);
}

