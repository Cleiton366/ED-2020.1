#include "calc.hpp"
#include <iostream>
using namespace std;

calc::calc(){
    this->primeiro = nullptr;
    this->primeiro_area_memoria = nullptr;
    this->primeiro_resultado = nullptr;
    this->tamanho = 0;
    this->tam_resultado = 0;
    this->tam_area_memoria = 0;
}
calc::no_encadeado::no_encadeado(int num, no_encadeado* proximo){
    this->numero = num;
    this->proximo = proximo;
}
calc::resultado::resultado(int num, resultado* proximo){
    this->numero = num;
    this->proximo = proximo;
}
calc::area_memoria::area_memoria(int num, area_memoria* proximo){
    this->numero = num;
    this->proximo = proximo;
}

bool calc::inserir_em(int elemento, int indice) {
    if(indice == 0) {
        no_encadeado* novo_no = new no_encadeado(elemento, this->primeiro);
        this->primeiro = novo_no;
        this->tamanho++;
        return true;
    } else {    
        no_encadeado* anterior = obter_no_em(indice - 1);

        if(anterior != nullptr) {
            no_encadeado* novo_no = new no_encadeado(elemento);
            novo_no->proximo = anterior->proximo;
            anterior->proximo = novo_no;
            this->tamanho++;
            return true;
        } else {
            return false;
        }
    }
}

bool calc::inserir_num(int num){
    if(this->primeiro == nullptr){
       no_encadeado* novo_no = new no_encadeado(num, nullptr);
       this->primeiro = novo_no;
       this->tamanho++;
       return true;
    } else{
        no_encadeado* no = this->primeiro;
        while(no->proximo != nullptr){
            no = no->proximo; 
        }
        no_encadeado* novo_no = new no_encadeado(num, nullptr);
        no->proximo = novo_no;
        this->tamanho++;
        return true;
    }
    return false;
}

bool calc::inserir_result(int num){
    if(this->primeiro_resultado == nullptr){
       resultado* novo_no = new resultado(num, nullptr);
       this->primeiro_resultado = novo_no;
       this->tam_resultado++;
       return true;
    } else{
        resultado* no = this->primeiro_resultado;
        while(no->proximo != nullptr){
            no = no->proximo; 
        }
        resultado* novo_no = new resultado(num, nullptr);
        no->proximo = novo_no;
        this->tam_resultado++;
        return true;
    }
    return false;
}

bool calc::inserir_area(int num){
    if(this->primeiro_area_memoria == nullptr){
       area_memoria* novo_no = new area_memoria(num, nullptr);
       this->primeiro_area_memoria = novo_no;
       this->tam_area_memoria++;
       return true;
    } else{
        area_memoria* no = this->primeiro_area_memoria;
        while(no->proximo != nullptr){
            no = no->proximo; 
        }
        area_memoria* novo_no = new area_memoria(num, nullptr);
        no->proximo = novo_no;
        this->tam_area_memoria++;
        return true;
    }
    return false;
}



void calc::exibir_resultado(){
    resultado* no = this->primeiro_resultado;
    while(no != nullptr){
        cout << no->numero;
        no = no->proximo;
    }
}

void calc::exibir(){
    no_encadeado* no = this->primeiro;
    int i = 0;
    while(i < tamanho){
        cout << "Elemento no indice(" << i << "):"<< no->numero << endl;
        i++;
        no = no->proximo;
    }
}

int calc::somar_num(no_encadeado* num1 ,no_encadeado* num2, int indice, int resto, int tam, calc b){
    int soma = 0;

    while(indice < tam){
        if(num2->proximo == nullptr && resto == 1){
            this->inserir_num(0);
            b.inserir_num(0);
            tam++;
        }
        soma = (num1->numero + num2->numero) + resto;
        if(soma > 9){
        this->inserir_result(soma-10);
        return somar_num(num1->proximo, num2->proximo, indice + 1, 1, tam, b);
        }else {
            this->inserir_result(soma);
            return somar_num(num1->proximo, num2->proximo, indice + 1, 0, tam, b);
        }
    }
    
}

int calc::subtrair_num(no_encadeado* num1 ,no_encadeado* num2, int indice, int emprestar, int tam, int tam2){
    int subtrair = 0;
    if(tam > tam2) preencher_zeros(tam);
    while(indice < tam){
        if(emprestar == 10) num1->numero = num1->numero - 1;
        emprestar = 0;
        if(num2->numero > num1->numero && num2->proximo != nullptr) emprestar = 10;
        subtrair = (num1->numero + emprestar) - num2->numero;
        inserir_result(subtrair);
        return subtrair_num(num1->proximo, num2->proximo, indice + 1, emprestar, tam, tam2);
    }  
    
}

void calc::multiplicar_num(no_encadeado* num1 ,no_encadeado* num2, calc aux, calc soma, calc aux_num2){
    
    calc sub;
    sub.inserir_num(1);
    aux.inserir_num(0);
    aux_num2.inverter_list(1);
    sub.preencher_zeros(aux_num2.get_tamanho());

    while(aux_num2.tamanho > 0){       
        
        aux_num2.subtrair_num(aux_num2.get_primeiro(), sub.get_primeiro(), 0, 0, aux_num2.get_tamanho(), sub.get_tamanho());
        aux_num2.resultado_para_lista(aux_num2);
        
        

        aux.somar_num(aux.get_primeiro(), soma.get_primeiro(), 0, 0, soma.get_tamanho(), soma);
        aux.resultado_para_lista(aux);
    }
    aux.resultado_para_lista(aux);
    
    no_encadeado* no = aux.get_primeiro();
    while(no->proximo != nullptr){
        this->inserir_result(no->numero);
        no = no->proximo;
    }
    
}

calc::no_encadeado* calc::resultado_para_lista(calc num){
    resultado* no = this->primeiro_resultado;
    num.resetar_lista();
    while(no != nullptr){
        num.inserir_num(no->numero);
        no = no->proximo;
    }
    this->resetar_result();
    return num.primeiro;
}

void calc::memoria_para_lista(area_memoria* memoria){
    while(memoria != nullptr){
        inserir_num(memoria->numero);
        memoria = memoria->proximo;
    }
}

void calc::preencher_zeros_mult(calc &soma, calc &aux, int indice){

    
    // tam -= 1;
    int i = 0;
    while(i < indice){
        aux.inserir_em(0,0);
        i++;
    }
    int tam = aux.get_tamanho();
    int k = 0;    
    if(indice == 0){
        while(k < aux.get_tamanho()){
            soma.inserir_num(0);
            k++;
        }
    }else{
        i = 0;
        while(i < tam - soma.get_tamanho()){
            soma.inserir_num(0);
            i++;
        }
    }
}

void calc::copiar(calc num){
    no_encadeado* no = num.get_primeiro();
    while(no){
        this->inserir_num(no->numero);
        no = no->proximo;
    }
}


bool calc::guardar_result_na_area_memoria(resultado* result){
    while(result != nullptr) {
        inserir_area(result->numero);
        result = result->proximo;
    }    
}

void calc::resetar_memoria(){
    this->primeiro_area_memoria = nullptr;
    this->tam_area_memoria = 0;
}

void calc::resetar_result(){
    this->primeiro_resultado = nullptr;
    this->tam_resultado = 0;
}

void calc::resetar_lista(){
    this->primeiro = nullptr;
    this->tamanho = 0;
}
void calc::exibir_area_memoria(){
    area_memoria* no = this->primeiro_area_memoria;
    while(no != nullptr){
        cout << no->numero;
        no = no->proximo;
    }
}

void calc::inverter_list(int op){
//op 1 = inverter lista // op 2 = inverter resultado // op 3 = inverter area memoria
if(op == 1){
    no_encadeado* atual = this->primeiro;
    no_encadeado* anterior = nullptr;
    no_encadeado* proximo;
    while(atual != nullptr){
       proximo = atual->proximo;
       atual->proximo = anterior;
       anterior = atual;
       atual = proximo;
    }
    this->primeiro = anterior;
}else if(op == 2){
    resultado* atual = this->primeiro_resultado;
    resultado* anterior = nullptr;
    resultado* proximo;
    while(atual != nullptr){
       proximo = atual->proximo;
       atual->proximo = anterior;
       anterior = atual;
       atual = proximo;
    }
    this->primeiro_resultado = anterior;
    }else if(op == 3){
        area_memoria* atual = this->primeiro_area_memoria;
        area_memoria* anterior = nullptr;
        area_memoria* proximo;
        while(atual != nullptr){
            proximo = atual->proximo;
            atual->proximo = anterior;
            anterior = atual;
            atual = proximo;
        }
        this->primeiro_area_memoria = anterior;
    }
}

calc::no_encadeado* calc::obter_no_em(int indice){
    int i = 0;
    no_encadeado* no = this->primeiro;
    while(i < indice){
        no = no->proximo;
        i++;
    }
    return no;
}

void calc::preencher_zeros(int tam){
    while(this->tamanho < tam){
        this->inserir_em(0, 0);
    }
}
