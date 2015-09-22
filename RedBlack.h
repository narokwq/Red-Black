#ifndef RED_BLACK_REDBLACK_H
#define RED_BLACK_REDBLACK_H

typedef struct elemento{
    int valor;
}t_elemento;

typedef struct no{
    t_elemento elemento;
    enum Cor {RED, BLACK} cor;
    struct no *dir, *esq, *pai;
}t_no;

typedef t_no *arvore;

t_no* criar_arvore();
t_no* criar_no(t_elemento elemento);                //Cria um nó com seu determinado elemento
int is_vazio(arvore tree);                          //Verifica se a Arvore esta vazia
int inserir(arvore *tree, t_elemento elemento);     //Insere um nó na arvore
t_no* buscar(arvore tree, t_elemento elementoB);    //Busca um elemento na arvore
int remover(arvore *tree, int elemento);            //Remove um nó da arvore
void pre_ordem(arvore tree);
void in_ordem(arvore tree);
void pos_ordem(arvore tree);

#endif //RED_BLACK_REDBLACK_H
