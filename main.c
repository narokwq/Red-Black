#include <stdio.h>
#include "RedBlack.h"

int main(){
    t_no no = {1, 'V', NULL, NULL, NULL};

    arvore t = &no;

    if(is_vazio(t))
        printf("%s","Vazio");
    else
        printf("%s","Cheio");
}