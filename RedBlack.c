#include <stdio.h>
#include <stdlib.h>
#include "RedBlack.h"

void inserir_fix(arvore tree, t_no* no);
void rotacionar_direita(arvore tree, t_no* no);
void rotacionar_esquerda(arvore tree, t_no* no);

int comparar(t_elemento elemento1, t_elemento elemento2){
    return elemento1.valor - elemento2.valor;
}

int is_vazio(arvore tree){
    return tree->raiz == tree->nulo;
}
t_arvore* criar_arvore() {
    t_arvore* tree = (t_arvore* ) malloc(sizeof(t_arvore));
    t_no* nulo = (t_no *) malloc(sizeof(t_no));
    if (tree) {
        if(nulo)
            nulo->pai = nulo->dir = nulo->esq = nulo;
            nulo->cor = B;
            tree->raiz = tree->nulo = nulo;
    }
    return tree;
}

t_no* criar_no(arvore  raiz, t_elemento elemento) {
    t_no *no = (t_no *) malloc(sizeof(t_no));
    if (no) {
        no->elemento = elemento;
        no->dir = no->esq = no->pai = raiz->nulo;
        no->cor = R;
    }

    return no;
}

int inserir_na_arvore(arvore tree, t_no** no, t_no* pai, t_no* novo_no){
    int ok;
    if(*no == tree->nulo){
        *no = novo_no;
        (*no)->pai = pai;
        return 1;
    }

    if(comparar((*no)->elemento, novo_no->elemento) < 0){
        ok = inserir_na_arvore(tree ,&((*no)->dir), *no, novo_no);
    }else if(comparar((*no)->elemento, novo_no->elemento) > 0) {
        ok = inserir_na_arvore(tree ,&((*no)->esq), *no, novo_no);
    }else{
        ok = 0;
    }

    return ok;
}

int inserir(arvore tree, t_elemento elemento){
    t_no* novo_no = criar_no(tree, elemento);
    if(novo_no == NULL){
        return 0;
    }
    if(inserir_na_arvore(tree, &(tree->raiz), tree->nulo, novo_no)){
        inserir_fix(tree, novo_no);
        return 1;
    }
    return 0;
}

//Preguica de implementar
void inserir_fix(arvore tree, t_no* no){
    t_no* tio;
    while(no->pai->cor == R){
        if(no->pai == no->pai->pai->esq){

            tio = no->pai->pai->dir;
            if(tio->cor == R){
                no->pai->cor = B;
                tio->cor = B;
                no->pai->pai->cor = R;
                no = no->pai->pai;
            }else {
                if(no == no->pai->dir){
                    no = no->pai;
                    rotacionar_esquerda(tree, no);
                }
                no->pai->cor = B;
                no->pai->pai->cor = R;
                rotacionar_direita(tree, no->pai->pai);
            }



        }else{
            tio = no->pai->pai->esq;
            if(tio->cor == R){
                no->pai->cor = B;
                tio->cor = B;
                no->pai->pai->cor = R;
                no = no->pai->pai;
            }else {
                if(no == no->pai->esq){
                    no = no->pai;
                    rotacionar_direita(tree, no);
                }
                no->pai->cor = B;
                no->pai->pai->cor = R;
                rotacionar_esquerda(tree, no->pai->pai);
            }



        }

    }
    tree->raiz->cor = B;
}

t_no* buscar(t_no* tree, t_elemento elementoB){
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

int remover(arvore tree, int elemento){
    //TODO
}

void rotacionar_direita(arvore tree, t_no* no){
    t_no * aux = no->esq;
    no->esq = aux->dir;

    if(aux->dir != tree->nulo)
        aux->dir->pai = no;
    aux->pai = no->pai;

    if(no->pai == tree->nulo)
        tree->raiz = aux;
    else if(no == no->pai->esq)
        no->pai->esq = aux;
    else
        no->pai->dir = aux;

    aux->dir = no;
    no->pai = aux;
}

void rotacionar_esquerda(arvore tree, t_no* no){
    t_no * aux = no->dir;
    no->dir = aux->esq;

    if(aux->esq != tree->nulo)
        aux->esq->pai = no;
    aux->pai = no->pai;

    if(no->pai == tree->nulo)
        tree->raiz = aux;
    else if(no == no->pai->esq)
        no->pai->esq = aux;
    else
        no->pai->dir = aux;

    aux->esq = no;
    no->pai = aux;

}

void pre_ordem(arvore tree, t_no* raiz){
    if(raiz != tree->nulo) {
        printf("%d ", raiz->elemento.valor);
        if(raiz->cor == R)
            printf("Vermelho\n");
        else
            printf("Preto\n");
        pre_ordem(tree, raiz->esq);
        pre_ordem(tree, raiz->dir);
    }
}

void in_ordem(arvore tree, t_no* raiz){
    if(raiz != tree->nulo) {
        in_ordem(tree, raiz->esq);
        printf("%d : ", raiz->elemento.valor);
        if(raiz->cor == R)
            printf("Vermelho\n");
        else
            printf("Preto\n");
        in_ordem(tree, raiz->dir);
    }
}

void pos_ordem(arvore tree, t_no* raiz){
    if(raiz != tree->nulo) {
        pos_ordem(tree, raiz->esq);
        pos_ordem(tree, raiz->dir);
        printf("%d ", raiz->elemento.valor);
        if(raiz->cor == R)
            printf("Vermelho\n");
        else
            printf("Preto\n");
    }
}