#include <stdio.h>
#include <string.h>
#include "inventario.h"


int main (int argc, char *argv[]) {

    char nombres[10][20];
    int n = 0;
    float precio[10];
    int op = 0;
    int cont = 0;
    float total = 0;
    float caro = 0;

    do{

        op = menu();

        switch (op)
        {
        case 1:

            printf("NUMERO DE PRODUCTOS QUE VA A INGRESAR: ");
            scanf("%d", &n);

            if (cont + n <= 10)
            {
                Nombre_Productos(nombres + cont, n);
                Precios(precio + cont, n);
                cont += n;
            }
            else
            {
                printf("***************************************************************************");
                printf("\nINVENTARIO LLENO, NO SE PUEDEN AGREGAR MAS PRODUCTOS.\n");
                printf("***************************************************************************");
            }

            break;

        case 2:

            total = precio_total(precio, cont);
            printf("TOTAL DE TODO EL ALMACEN: %.2f", total);
            break;

        case 3:

            if (cont > 0)
            {
                int indice =mayor(precio, cont);
                printf("\nNOMBRE: %s | PRECIO:  %.2f",nombres[indice], precio[indice]);
                break;
            }
            else 
            {
                printf("\n****************************\n");
                printf("NO HAY PRODUCTOS INGRESADOS.\n");
                printf("****************************\n");
                
            }
                break;

        case 4:

            if (cont > 0)
            {
                int indice =menor(precio, cont);
                printf("\nNOMBRE: %s | PRECIO:  %.2f\n",nombres[indice], precio[indice]);
                break;
            }
            else 
            {
                printf("\n****************************\n");
                printf("NO HAY PRODUCTOS INGRESADOS.\n");
                printf("****************************\n");
                
            }

            break;
            
        case 5:

            {
            float respuesta = promedio(precio, cont);
            printf("EL PROMEDIO DE TODO ES: %.2f", respuesta);
            break;
            }

        case 6:

            if (cont > 0)
            {
                {
                int lugar = encontrar_producto(nombres, cont);

                    if (lugar != -1)
                    {
                        printf("\nPRODUCTO ENCONTRADO | NOMBRE: %s | PRECIO: %.2f\n", nombres[lugar], precio[lugar]);
                    }
                    else 
                    {
                        printf("\nPRODUCTO NO ENCONTRADO.\n");
                    }
                }
            }
            else 
            {
                printf("\nNO HAY PRODUCTOS INGRESADOS.\n");
            }

                break;
        case 7:

            printf("\nSALIENDO.....");

            break;
        }
    }while (op != 7);
    

    return 0;
}
