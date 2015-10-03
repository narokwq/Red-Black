#include <stdio.h>
#include "RedBlack.h"




int main(){
    t_elemento no = {10};
    t_elemento no2 = {5};
    t_elemento no3 = {15};
    t_elemento no4 = {2};
    t_elemento no5 = {12};
    t_elemento no6 = {8};
    t_elemento no7 = {18};

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
    exibirGraficamente(t, 30, 15);
    printf("\n\n");


    getchar();
}

