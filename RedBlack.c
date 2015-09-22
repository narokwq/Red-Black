#include <stdio.h>
#include <stdlib.h>
#include "RedBlack.h"

int comparar(t_elemento elemento1, t_elemento elemento2){
    return elemento1.valor < elemento2.valor;
}

int is_vazio(arvore tree){
    return tree == NULL;
}
t_no* criar_arvore() {
    return NULL;
}

t_no* criar_no(t_elemento elemento) {
    t_no *no = (t_no *) malloc(sizeof(t_no));
    if (no) {
        no->elemento = elemento;
        no->dir = no->esq = no->pai = NULL;
        no->cor = RED;
    }

    return no;
}

int inserir_na_arvore(arvore *tree, arvore pai, arvore novo_no){
    int ok;
    if(*tree == NULL){
        *tree = novo_no;
        (*tree)->pai = pai;

        return 1;
    }

    if(comparar((*tree)->elemento, novo_no->elemento) < 0){
        ok = inserir_na_arvore(&((*tree)->dir), *tree, novo_no);
    }else if(comparar((*tree)->elemento, novo_no->elemento) > 0) {
        ok = inserir_na_arvore(&((*tree)->esq), *tree, novo_no);
    }else{
        ok = 0;
    }

    return ok;
}

int inserir(arvore *tree, t_elemento elemento){
    t_no* novo_no = criar_no(elemento);
    if(novo_no == NULL){
        return 0;
    }
    if(inserir_na_arvore(tree, NULL, novo_no)){
        inserir_fix(tree, novo_no);
        return 1;
    }
    return 0;
}
//Preguica de implementar

void inserir_fix(arvore tree, int elemento){
    //TODO
}

t_no* buscar(arvore tree, t_elemento elementoB){
   while(tree != NULL){
       if(!comparar(tree->elemento, elementoB))
           return tree;
       else if(comparar(tree->elemento, elementoB) > 0)
           tree = tree->esq;
       else
           tree = tree->dir;
   }
    return tree;
}

int remover(arvore *tree, int elemento){
    //TODO
}

void rotacionar_direita(arvore *tree, arvore no){
    t_no * aux = no->esq;
    no->esq = aux->dir;

    if(aux->dir != NULL)
        aux->dir->pai = no;
    aux->pai = no->pai;

    if(no->pai == NULL)
        *tree = aux;
    else if(no == no->pai->esq)
        no->pai->esq = aux;
    else
        no->pai->dir = aux;

    aux->dir = no;
    no->pai = aux;
}

void rotacionar_esquerda(arvore *tree, arvore no){
    t_no * aux = no->dir;
    no->dir = aux->esq;

    if(aux->esq != NULL)
        aux->esq->pai = no;
    aux->pai = no->pai;

    if(no->pai == NULL)
        *tree = aux;
    else if(no == no->pai->esq)
        no->pai->esq = aux;
    else
        no->pai->dir = aux;

    aux->esq = no;
    no->pai = aux;

}