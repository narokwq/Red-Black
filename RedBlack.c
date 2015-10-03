#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "RedBlack.h"

void inserir_fix(arvore tree, t_no* no);
void rotacionar_direita(arvore tree, t_no* no);
void rotacionar_esquerda(arvore tree, t_no* no);
void exGraficamente(arvore tree, t_no* no, int col, int lin, int desloc);

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
            nulo->cor = BLACK;
            tree->raiz = tree->nulo = nulo;
    }
    return tree;
}

t_no* criar_no(arvore  raiz, t_elemento elemento) {
    t_no *no = (t_no *) malloc(sizeof(t_no));
    if (no) {
        no->elemento = elemento;
        no->dir = no->esq = no->pai = raiz->nulo;
        no->cor = RED;
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


void inserir_fix(arvore tree, t_no* no){
    t_no* tio;
    while(no->pai->cor == RED){
        if(no->pai == no->pai->pai->esq){

            tio = no->pai->pai->dir;
            if(tio->cor == RED){
                no->pai->cor = BLACK;
                tio->cor = BLACK;
                no->pai->pai->cor = RED;
                no = no->pai->pai;
            }else {
                if(no == no->pai->dir){
                    no = no->pai;
                    rotacionar_esquerda(tree, no);
                }
                no->pai->cor = BLACK;
                no->pai->pai->cor = RED;
                rotacionar_direita(tree, no->pai->pai);
            }

        }else{
            tio = no->pai->pai->esq;
            if(tio->cor == RED){
                no->pai->cor = BLACK;
                tio->cor = BLACK;
                no->pai->pai->cor = RED;
                no = no->pai->pai;
            }else {
                if(no == no->pai->esq){
                    no = no->pai;
                    rotacionar_direita(tree, no);
                }
                no->pai->cor = BLACK;
                no->pai->pai->cor = RED;
                rotacionar_esquerda(tree, no->pai->pai);
            }

        }

    }
    tree->raiz->cor = BLACK;
}

t_no* buscar(arvore tree, t_elemento elementoB){
   t_no* no = tree->raiz;
   while(no != tree->nulo){
       if(!comparar(no->elemento, elementoB))
           return no;
       else if(comparar(no->elemento, elementoB) > 0)
           no = no->esq;
       else
           no = no->dir;
   }
    return NULL;
}

int remover(arvore tree, int elemento){
    //TODO
}

int remover_fix(arvore tree, int elemento){
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
        if(raiz->cor == RED)
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
        if(raiz->cor == RED)
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
        if(raiz->cor == RED)
            printf("Vermelho\n");
        else
            printf("Preto\n");
    }
}

COORD getCursorPosition(){
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return info.dwCursorPosition;
}

void gotoxy(int x, int y){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cord;
    cord.X = (short) x;
    cord.Y = (short) y;

    SetConsoleCursorPosition(hStdout, cord);
}

void exibirGraficamente(arvore tree, int col, int desloc){
    exGraficamente(tree, tree->raiz, col,  getCursorPosition().Y, desloc);
}

void exGraficamente(arvore tree, t_no* no, int col, int lin, int desloc)
{
    if (no == tree->nulo)
        return;
    gotoxy(col,lin);
    printf("%d", no->elemento.valor);
    if (no->esq != tree->nulo)
        exGraficamente(tree, no->esq,col-desloc,lin+2,desloc/2+1);
    if (no->dir != tree->nulo)
        exGraficamente(tree, no->dir,col+desloc,lin+2,desloc/2+1);
}
