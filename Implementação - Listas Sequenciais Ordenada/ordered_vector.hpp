class vector {
    private:
        // Ponteiro para o vetor que usaremos para armazenar os elementos.
        int *vetor;
        // Contagem da quantidade de elementos efetivamente presentes na lista.
        int tamanho; // FIXME Veja que a correspondência desse valor e do último índice ocupado está incorreta em alguns lugares do código.
        // Contagem do número de índices alocados no vetor "vetor".
        int capacidade;

    public:
        // Construtores
        vector(int capacidade);
        vector(int tamanho, int inicial);

        // Métodos de "Coleção"
        bool inserir(int elemento, vector vetor);
        bool remover(int elemento);
        bool pertence(int elemento);

        int obter_tamanho() { return tamanho; }

        // Métodos de "Lista"
        bool remover_de(int indice);

        int obter_elemento_em(int indice);
        int obter_indice_de(int elemento);

        void printar(vector vetor);

        // Métodos auxiliares
        int obter_capacidade() { return capacidade; }
        void ordenar(vector vetor);
};