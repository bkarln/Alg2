#include <stdio.h>

int main (){
    int i, n;
    int  a, b, c, d, x;
        
    scanf("%i", &n);
    for (i = 0; i < n; i++) {
        scanf("%i %i %i %i %i", &a, &b, &c, &d, &x);
        printf("%i %i %i %i\n", cubo(x), quadrado(x), multiplica(c,x), pol_cubo(a, b, c, d, x));
    }
}

int multiplica (int x1, int x2){
	int m = x1*x2;	
return m;
}

int quadrado (int x){
	int qd = (x*x);	
return qd;	
} 

int cubo (int x){
	int c = (x*x*x);
return c;
}

int pol_cubo(int a, int b, int c, int d, int x) {
	int pc = (multiplica(a,cubo(x)) + multiplica(b,quadrado(x)) + multiplica(c,x) + d);
return pc;	
}