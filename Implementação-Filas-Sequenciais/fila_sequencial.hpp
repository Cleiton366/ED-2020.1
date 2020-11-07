class fila_sequencial {
    private:
        // Ponteiro para o vetor que usaremos para armazenar os elementos.
        int *fila;
        // Contagem da quantidade de elementos efetivamente presentes na lista.
        int tamanho; // FIXME Veja que a correspondência desse valor e do último índice ocupado está incorreta em alguns lugares do código.
        // Contagem do número de índices alocados no vetor "vetor".
        int capacidade;
        //indice do primeiro elemento na fila
        int inicio; 

    public:
        // Construtores
        fila_sequencial(int capacidade);

        // Métodos de "Coleção"
        bool enfilerar(int elemento);
        bool desenfilerar();

        // Métodos auxiliares
        int obter_capacidade() { return capacidade; }
        void printar();
};