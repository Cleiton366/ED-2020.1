#include <string>
#include <time.h>
class gerenciador{
    private:
    class tarefa {
        public:
        std::string descricao;
        bool estado;
        int data_criacao[3];
        int data_prazo[3];
        tarefa();
        tarefa(std::string descricao, bool estado, int data_criacao[3], int data_prazo[3]);
        
    };
    tarefa* vetor;
    int tamanho;
    int qtd;
    int filtro;

    public:

    gerenciador();
    gerenciador(int tamanho);

    bool adicionar_tarefa(std::string descricao, bool estado, int data_prazo[3]);
    bool remover_tarefa(int indice);
    bool marcar_concluido(int indice);
    bool reabrir_tarefa(int indice);
    bool adicionar_tarefa_em(int indice, tarefa* t);
    
    void filtrar(int op);
    void exibir(gerenciador a);

    void ordenar_criacao();
    void ordenar_prazo();
    void ordenar_manual(int indice_alvo, int outro, int op);

    void preencher_datas(int data_prazo[3]);
    void copiar_datas(tarefa* t, int indice);
    int get_filtro(){return filtro;}
    int get_qtd(){return qtd;}
    

    void limpar();
    void frezar_tela();
};