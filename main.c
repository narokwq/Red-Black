#include <stdio.h>
#include "RedBlack.h"

int main(){
    t_elemento no = {3};
    t_elemento no2 = {2};
    t_elemento no3 = {4};
    t_elemento no4 = {1};

    arvore t = criar_arvore();
    inserir(&t,no);
    inserir(&t,no2);
    inserir(&t,no3);
    inserir(&t,no4);


    pre_ordem(t);
    printf("\n");
    in_ordem(t);
    printf("\n");
    pos_ordem(t);
    printf("\n");



    printf("%d", 10<2);


    if(t->cor == RED)
        printf("%s","VERMELHO");
    else
        printf("%s","PRETO");
}