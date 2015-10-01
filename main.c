#include <stdio.h>
#include <windows.h>
#include "RedBlack.h"

COORD getCursorPosition();
void exibirGraficamente(arvore tree, t_no* no, int col, int lin, int desloc);

int main(){
    t_elemento no = {15};
    t_elemento no2 = {8};
    t_elemento no3 = {10};
    t_elemento no4 = {12};
    t_elemento no5 = {18};
    t_elemento no6 = {25};
    t_elemento no7 = {20};

    //Teste inserir sem verificar regras
    arvore t = criar_arvore();

    inserir(t,no);
    inserir(t,no2);
    inserir(t,no3);
    inserir(t,no4);
    inserir(t,no5);
    inserir(t,no6);
    inserir(t,no7);

    if(buscar(t, (t_elemento){9}))
        printf("Achou\n");
    else
        printf("Nao Achou\n");

    //Fim de teste
    printf("\nPre-ordem\n");
    pre_ordem(t, t->raiz);
    printf("\nIn-ordem\n");
    in_ordem(t, t->raiz);
    printf("\nPos-ordem\n");
    pos_ordem(t, t->raiz);
    printf("\n");
    printf("\nGraficamente\n");
    exibirGraficamente(t, t->raiz, 30, getCursorPosition().Y, 15);
    printf("\n\n");



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
void exibirGraficamente(arvore tree, t_no* no, int col, int lin, int desloc)
{
    if (no == tree->nulo)
        return;
    gotoxy(col,lin);
    printf("%d", no->elemento.valor);
    if (no->esq != tree->nulo)
        exibirGraficamente(tree, no->esq,col-desloc,lin+2,desloc/2+1);
    if (no->dir != tree->nulo)
        exibirGraficamente(tree, no->dir,col+desloc,lin+2,desloc/2+1);
}