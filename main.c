#include <stdio.h>
#include "funciones.h"

int main() {
    int a, b;

    printf("Ingrese el primer numero: ");
    if(scanf("%d", &a) != 1){
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Ingrese el segundo numero: ");
    if(scanf("%d", &b) != 1){
        printf("Entrada invalida.\n");
        return 1;
    }

    printf("Resultado de la suma: %d\n", suma(a, b));
    printf("Resultado de la resta: %d\n", resta(a, b));

    return 0;
}