class pilha_encadeada {
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
        no_encadeado* topo;
        

    public:
        pilha_encadeada();

        bool empilhar(int elemento);
        bool desempilhar();

        void printar();
};