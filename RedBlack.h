#ifndef RED_BLACK_REDBLACK_H
#define RED_BLACK_REDBLACK_H

typedef struct no{
    int elemento;
    char cor;
    struct no *dir, *esq, *pai;
}t_no;

typedef t_no *arvore;

int is_vazio(arvore tree);
int inserir(arvore *tree, int elemento);
void inserir_fix(arvore tree, int elemento);
int remover(arvore *tree, int elemento);
void rotacionar_direita(arvore tree);
void rotacionar_esquerda(arvore tree);

#endif //RED_BLACK_REDBLACK_H
