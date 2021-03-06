class list {

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
        // Contagem da quantidade de elementos presentes na lista.
        unsigned int tamanho;

    public:

        // Construtores
        list();
        list(unsigned int tamanho, int primeiro);


        // Métodos de "Coleção"
        unsigned int obter_tamanho() { return tamanho; }

        bool inserir(int elemento);
        bool remover(int elemento);
        bool pertence(int elemento);


        // Métodos de "Lista"
        bool inserir_em(unsigned int indice, int elemento);
        bool remover_de(unsigned int indice);

        int obter_elemento_em(unsigned int indice);
        int obter_indice_de(int elemento);
        void printar(list lista);

        protected:
        // Métodos auxiliares
        no_encadeado* obter_no_em(int indice);
        no_encadeado* obter_no_anterior_a(int valor);

};