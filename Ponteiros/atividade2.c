#include <stdio.h>
#include <string.h>

void *achar (void *p, char *frase){
    int inicio = *(int*)p;
    int i;
    for (i = inicio; i<strlen(frase); i++){
        if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u'
            || frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U' ){
            return &frase[i];
        }
    }
    return &frase[i-1];
}

int main (){
    int n = 7;
    void* p = &n;
    char frase[62] = "the quick brown fox jumps over the lazy dog";
    p = achar(p, frase);
    printf("%c", *(char*) p);
}