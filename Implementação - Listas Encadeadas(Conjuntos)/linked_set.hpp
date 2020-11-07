// NOTE Em C++, a ocorrência de `const` após o nome de um método indica a promessa
//      de que tal método não irá fazer alterações nas variáveis do objeto e que
//      pode ser chamado em objetos declarados como `const`.

class linked_set {
    private:
        // Classe que representa os componentes da lista na memória
        class no_encadeado {
        public:
            int elemento;
            // Referência para o nó que vem após o atual
            no_encadeado* proximo;

            // Construtor
            no_encadeado(int valor, no_encadeado* proximo = nullptr);
        };
        no_encadeado* primeiro;
        // Contagem da quantidade de elementos presentes na lista.
        unsigned int tamanho;

    public:
        // Construtores
        linked_set();

        // Métodos de "Coleção"
        bool inserir(int elemento);
        bool remover(int elemento);
        bool pertence(int elemento) const;

        unsigned int obter_tamanho() const { return tamanho; }

        // Métodos de "Conjunto"

        // NOTE Em C++, o "&" antes do nome da variável, neste caso, significa que iremos receber
        //      o outro conjunto por referência. Você não precisa se preocupar com isso, pois
        //      a sintaxe dentro do método funcionará como antes.
        void uniao_com(linked_set &conjunto);
        void intersecao_com(linked_set &conjunto);
        bool esta_contido_em(linked_set &conjunto);
        void ordenar();
        int e_igual(int i, int elemento);
        int obter_indice_de(int elemento);
        void printar(linked_set lista);
    protected:
        // Métodos auxiliares
        no_encadeado* obter_no_em(int indice);
        no_encadeado* obter_no_anterior_a(int valor);
};