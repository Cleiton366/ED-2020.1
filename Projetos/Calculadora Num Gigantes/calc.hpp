class calc {

    private:
        class no_encadeado{
            public:
            int numero;
            no_encadeado* proximo;
            no_encadeado(int numero, no_encadeado* proximo = nullptr);
        };
        class resultado{
            public:
            int numero;
            resultado* proximo;
            resultado();
            resultado(int numero, resultado* proximo = nullptr);
        };
        class area_memoria{
            public:
            int numero;
            area_memoria* proximo;
            area_memoria(int numero, area_memoria* proximo = nullptr);
        };
        no_encadeado* primeiro;
        resultado* primeiro_resultado;
        area_memoria* primeiro_area_memoria;
        int tamanho;
        int tam_resultado;
        int tam_area_memoria;
    public:

    calc();
    calc(int tamanho, int primeiro);

    bool inserir_em(int elemento, int indice);
    bool inserir_num(int elemento);
    bool inserir_result(int elemento);
    bool inserir_area(int elemeento);
    void exibir_resultado();
    
    int somar_num(no_encadeado* num1, no_encadeado* num2,int indice, int resto, int tam, calc b);
    int subtrair_num(no_encadeado* num1 ,no_encadeado* num2, int indice, int emprestar, int tam, int tam2);
    void multiplicar_num(no_encadeado* num1 ,no_encadeado* num2, calc aux, calc soma, calc aux_num2);
    //int multiplicar_num(no_encadeado* num1 ,no_encadeado* num2, int tam, int indice, int resto, calc aux, calc soma);
    

    bool guardar_result_na_area_memoria(resultado* result);
    void resetar_memoria();
    void resetar_result();
    void resetar_lista();
    void exibir_area_memoria();
    void copiar(calc lista);

    void exibir();

    void memoria_para_lista(area_memoria* memoria);
    no_encadeado* resultado_para_lista(calc soma);
    no_encadeado* obter_no_em(int indice);
    no_encadeado* get_primeiro(){return primeiro;}
    resultado* get_resultado(){return primeiro_resultado;}
    area_memoria* get_memoria(){return primeiro_area_memoria;}
    int get_tamanho(){return tamanho;}
    int get_tam_result(){return tam_resultado;}
    int get_tam_area(){return tam_area_memoria;}
    void inverter_list(int op);
    void preencher_zeros(int tam);
    void preencher_zeros_mult(calc &num1, calc &num2, int indice);

};