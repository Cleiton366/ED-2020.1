class pilha_sequencial {
    private:
        int *pilha;
        int capacidade;
        int topo;

    public:

        pilha_sequencial(int capacidade);

        bool empilhar(int elemento);
        bool desempilhar();

        void printar();

};