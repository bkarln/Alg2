#include <stdio.h>

void ordenar (int *a, int *b, int *c){
    int *guardavalor = NULL;
        if (*a > *b){
            guardavalor = a;
            a = b;
            b = guardavalor;
        }
        if (*a > *c){
            guardavalor = a;
            a = c;
            c = guardavalor;
        }
        if (*b > *c){
            guardavalor = b;
            b = c;
            c = guardavalor;
        }
    printf("%d %d %d", *a, *b, *c);
}

void main (){
    int a, b, c;
    a=1;
    b=3;
    c=2;
    ordenar(&a, &b, &c);
} 