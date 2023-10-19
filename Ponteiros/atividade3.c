#include <stdio.h>

double *max (double *v, int tam){
double *maior = &v[0];    
    for (int i = 0; i<= tam; i++){
        if (*maior < v[i]){
            maior = &v[i];
        }
    }
    return maior;
    
}

void main () {
    double v[5]={2.6, 13.2, 1.65, 0.99, 11.9};
    double *p_max;
    p_max = max (v, 5);
    printf("%.2lf\n", *p_max);
}