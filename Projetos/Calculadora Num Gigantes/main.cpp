#include <iostream>
#include "calc.hpp"
#include <string>

using namespace std;

void limpar(){
    system("CLS");
}

void frezar_tela(){
    cout << "Aperte qualquer tecla para continuar" << endl;
    std::string s;
    getline(cin,s);
    getline(cin,s);
}



int main(){

calc a;
calc b;
calc aux;
calc aux_num2;
calc aux2;
calc soma;
bool menu = true;
int num = 0;

while(menu){
    //cout << "" << endl;
    int op;
    limpar();
    cout << "Bem Vindo a calculadora de numero gigantes!" << endl;

    cout << "1  | Ler numeros " << endl;
    cout << "2  | Somar" << endl;
    cout << "3  | Subtrair" << endl;
    cout << "4  | Multiplicar " << endl;
    cout << "5  | Exibir resultado" << endl;
    cout << "6  | Resetar resultado" << endl;
    cout << "7  | Guardar Resultado na memoria " << endl;
    cout << "8  | Resetar memoria " << endl;
    cout << "9  | Exibir valor na memoria " << endl;
    cout << "10 | Fazer uso do valor na memoria " << endl;
    cout << "11 | Sair " << endl;

    cin >> op;

    switch(op){
        case 1:

            a.resetar_lista();
            b.resetar_lista();
            limpar();
            
            cout << "Digite o primeiro numero" << endl;
            cout << "Somente numeros de 0 a 9 sao validos" << endl;
            cout << "Para finalizar, insira um numero maior que 9" << endl;
            
            while(1){
                num = 0;
                cin >> num;
                if(num > 9) break;
                a.inserir_num(num);
            }
            num = 0;
            limpar();
            cout << "Digite o segundo numero" << endl;
            cout << "Somente numeros de 0 a 9 sao validos" << endl;
            cout << "Para finalizar, insira um numero maior que 9" << endl;
            while(1){
                num = 0;
                cin >> num;
                if(num > 9) break;
                b.inserir_num(num);
            }
            limpar();
            cout << "Numeros adicionados com sucesso!" << endl;
            frezar_tela();

        break;

        case 2:

            if(a.get_tamanho() == 0 || b.get_tamanho() == 0){
                limpar();
                cout << "Um ou mais numeros estao vazios, impossivel calcular" << endl;
                cout << a.get_tamanho() << endl;
                cout << b.get_tamanho() << endl;
                frezar_tela();
                break;      
            }
            a.resetar_result();
            
            if(a.get_tamanho() > b.get_tamanho()) b.preencher_zeros(a.get_tamanho());
            if(b.get_tamanho() > a.get_tamanho()) a.preencher_zeros(b.get_tamanho());

            a.inverter_list(1);
            b.inverter_list(1);

            a.somar_num(a.get_primeiro(), b.get_primeiro(), 0, 0, b.get_tamanho(), b);

            a.inverter_list(1);
            b.inverter_list(1);

            limpar();
            cout << "Numeros somados!" << endl;
            frezar_tela();

        break;

        case 3:
            if(b.get_tamanho() > a.get_tamanho()){
                limpar();
                cout << "O primeiro numero nao pode ser menor que o segundo." << endl;
                frezar_tela();
                break;
            }
            a.resetar_result();

            if(a.get_tamanho() > b.get_tamanho()) b.preencher_zeros(a.get_tamanho());
            if(b.get_tamanho() > a.get_tamanho()) a.preencher_zeros(b.get_tamanho());

            a.inverter_list(1);
            b.inverter_list(1);

            a.subtrair_num(a.get_primeiro(), b.get_primeiro(), 0, 0, b.get_tamanho(), a.get_tamanho());

            a.inverter_list(1);
            b.inverter_list(1);
            
            limpar();
            cout << "Numeros subtraidos!" << endl;
            frezar_tela();
        break;

        case 4:
        a.resetar_result();
        aux.resetar_lista();
        aux.resetar_result();
        aux_num2.resetar_lista();
        soma.resetar_lista();
        aux_num2.copiar(b);
        soma.copiar(a);
  
        a.multiplicar_num(a.get_primeiro(), b.get_primeiro(), aux, soma, aux_num2);
        //limpar();
        cout << "Numeros multplicados!" << endl;
        frezar_tela();
        break;

        case 5:
            if(a.get_tam_result() == 0){
                limpar();
                cout << "Nao ha resultados a serem exibidos" << endl;
                frezar_tela();
                break;
            }
            limpar();
            cout << "Resultado do calculo: ";
            a.inverter_list(2);
            a.exibir_resultado();
            a.inverter_list(2);
            cout << endl;
            frezar_tela();
        break;

        case 6:
            if(a.get_tam_result() == 0){
                limpar();
                cout << "Nao ha resultado para ser apagado" << endl;
                frezar_tela();
                break;
            }
            a.resetar_result();
            limpar();
            cout << "Resultado resetado" << endl;
            frezar_tela();
        break;

        case 7:
            a.resetar_memoria();
            if(a.get_tam_result() == 0){
                limpar();
                cout << "Nao ha resultado para ser guardado na memoria" << endl;
                frezar_tela();
                break;
            }
            limpar();
            a.guardar_result_na_area_memoria(a.get_resultado());
            cout << "Resultado guardado na memoria" << endl;
            frezar_tela();
        break;

        case 8:
            if(a.get_tam_area() == 0){
                limpar();
                cout << "Memoria ja esta vazia" << endl;
                frezar_tela();
                break;
            }
            limpar();
            a.resetar_memoria();
            cout << "Memoria resetada" << endl;
            frezar_tela();
        break;

        case 9:
            if(a.get_tam_area() == 0){
                limpar();
                cout << "Memoria esta vazia" << endl;
                frezar_tela();
                break;
            }
            limpar();
            cout << "Valor guardado na area da memoria: ";
            
            a.inverter_list(3);
            a.exibir_area_memoria();
            a.inverter_list(3);
            cout << endl;
            frezar_tela();
        break;

        case 10:

            if(a.get_tam_area() == 0){
                limpar();
                cout << "Memoria esta vazia" << endl;
                frezar_tela();
                break;
            }
            aux2.resetar_lista();
            a.resetar_result();
            aux2.memoria_para_lista(a.get_memoria());
            aux2.inverter_list(1);
            limpar();
            while(1){

                cout << "Digita a opcao que deseja:" << endl;
                cout << "1 - Numero1 + Memoria:" << endl;
                cout << "2 - Numero2 + Memoria:" << endl;
                cout << "3 - Memoria - Numero1:" << endl;
                cout << "4 - Memoria - Numero2:" << endl;
                cout << "5 - Voltar para o menu inicial:" << endl;
                    
                int op2;
                cin >> op2;
                if(op2 == 1){
                    
                    if(a.get_tamanho() > aux2.get_tamanho()) aux2.preencher_zeros(a.get_tamanho());
                    if(aux2.get_tamanho() > a.get_tamanho()) a.preencher_zeros(aux2.get_tamanho());

                    a.inverter_list(1);
                    aux2.inverter_list(1);

                    a.somar_num(a.get_primeiro(), aux2.get_primeiro(), 0, 0, aux2.get_tamanho(), aux2);

                    a.inverter_list(1);
                    aux2.inverter_list(1);

                    limpar();
                    cout << "Numeros somados!" << endl;
                    frezar_tela();
                    break;
                }else if(op2 == 2){

                    if(b.get_tamanho() > aux2.get_tamanho()) aux2.preencher_zeros(b.get_tamanho());
                    if(aux2.get_tamanho() > b.get_tamanho()) b.preencher_zeros(aux2.get_tamanho());

                    b.inverter_list(1);
                    aux2.inverter_list(1);

                    a.somar_num(b.get_primeiro(), aux2.get_primeiro(), 0, 0, aux2.get_tamanho(), aux2);

                    b.inverter_list(1);
                    aux2.inverter_list(1);

                    limpar();
                    cout << "Numeros somados!" << endl;
                    frezar_tela();
                    break;
                }else if(op2 == 3){
                    if(aux2.get_tamanho() < a.get_tamanho()){
                        limpar();
                        cout << "O primeiro numero nao pode ser menor que o segundo." << endl;
                        frezar_tela();
                        break;
                    }
                    
                    if(a.get_tamanho() > aux2.get_tamanho()) aux2.preencher_zeros(a.get_tamanho());
                    if(aux2.get_tamanho() > a.get_tamanho()) a.preencher_zeros(aux2.get_tamanho());

                    a.inverter_list(1);
                    aux2.inverter_list(1);

                    a.subtrair_num(aux2.get_primeiro(), a.get_primeiro(), 0, 0, a.get_tamanho(), aux2.get_tamanho());

                    a.inverter_list(1);
                    aux2.inverter_list(1);

                    limpar();
                    cout << "Numeros subtraidos!" << endl;
                    frezar_tela();
                    break;
                }else if(op2 == 4){

                    if(b.get_tamanho() > aux2.get_tamanho()) aux2.preencher_zeros(b.get_tamanho());
                    if(aux2.get_tamanho() > b.get_tamanho()) b.preencher_zeros(aux2.get_tamanho());

                    b.inverter_list(1);
                    aux2.inverter_list(1);

                    a.subtrair_num(aux2.get_primeiro(), b.get_primeiro(), 0, 0, b.get_tamanho(), aux2.get_tamanho());

                    b.inverter_list(1);
                    aux2.inverter_list(1);
                    
                    limpar();
                    cout << "Numeros subtraidos!" << endl;
                    frezar_tela();
                    break;
                }else if(op2 == 5){
                    limpar();
                    break;
                }else {
                    limpar();
                    cout << "Opcao invalida!" << endl;
                    frezar_tela();
                }
            }
        break;

        case 11:
            limpar();
            menu = false;
        break;

    }

    
}



/*
a.inserir_num(2);
a.inserir_num(6);
a.inserir_num(6);
a.inserir_num(6);



b.inserir_num(1);
b.inserir_num(0);
b.inserir_num(0);





if(a.get_tamanho() > b.get_tamanho()) b.preencher_zeros(a.get_tamanho());
if(b.get_tamanho() > a.get_tamanho()) a.preencher_zeros(b.get_tamanho());

a.inverter_list(1);
b.inverter_list(1);

// a.multiplicar_num(a.get_primeiro(), b.get_primeiro(), b.get_tamanho(), 0, 0, aux, soma);
a.somar_num(a.get_primeiro(), b.get_primeiro(), 0, 0, b.get_tamanho(), b);
//a.subtrair_num(a.get_primeiro(), b.get_primeiro(), 0, 0, b.get_tamanho(), a.get_tamanho());
a.inverter_list(2);
a.exibir_resultado();
*/

    return 0;
}