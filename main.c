#include <stdio.h>
#include "RedBlack.h"

int main(){
    t_elemento no = {1};

    arvore t = criar_no(no); //criar_arvore();

    if(t->cor == RED)
        printf("%s","VERMELHO");
    else
        printf("%s","PRETO");
}