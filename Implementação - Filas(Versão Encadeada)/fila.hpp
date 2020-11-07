class fila {

    private:
        // Classe que representa os componentes da lista na memória
        class no_encadeado {
        public:
            int elemento;
            // Referência para o nó que vem após o atual
            no_encadeado* proximo;

            // Construtor
            no_encadeado(int elemento, no_encadeado* proximo = nullptr);
            
        };
        //ponteiro q guarda endereço de onde começa a lista
        no_encadeado* primeiro;
        //ponteiro q guarda endereço do ultimo elemento na lista
        no_encadeado* ultimo;
        // Contagem da quantidade de elementos presentes na lista.
        unsigned int tamanho;

    public:

        // Construtores
        fila();
        fila(int tamanho, int primeiro);


        // Métodos de "Coleção"
        int obter_tamanho() { return tamanho; }

        void enfilerar(int elemento);
        void desenfilerar();
        bool pertence(int elemento);


        // Métodos de "Filas"
        
        int obter_elemento_em(int indice);
        int obter_indice_de(int elemento);
        void printar(fila fila);

        protected:
        // Métodos auxiliares
        no_encadeado* obter_no_em(int indice);
        no_encadeado* obter_no_anterior_a(int valor);

};