#include <stdio.h>
#include <string.h>
#include "inventario.h"

int mostrarMenu()
{
    int opcion;

    printf("\n===== INVENTARIO =====\n");
    printf("1. Agregar productos\n");
    printf("2. Calcular valor total\n");
    printf("3. Mostrar producto más costoso\n");
    printf("4. Mostrar producto más económico\n");
    printf("5. Calcular precio promedio\n");
    printf("6. Buscar producto\n");
    printf("7. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    return opcion;
}

void ingresarNombres(char productos[][20], int cantidad)
{
    getchar();

    for(int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(productos[i], 20, stdin);
        productos[i][strcspn(productos[i], "\n")] = '\0';
    }
}

void ingresarPrecios(float precios[], int cantidad)
{
    for(int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el precio de %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

float calcularTotal(float precios[], int cantidad)
{
    float total = 0;

    for(int i = 0; i < cantidad; i++)
    {
        total += precios[i];
    }

    return total;
}

int obtenerMasCaro(float precios[], int cantidad)
{
    int posicion = 0;

    for(int i = 1; i < cantidad; i++)
    {
        if(precios[i] > precios[posicion])
        {
            posicion = i;
        }
    }

    return posicion;
}

int obtenerMasBarato(float precios[], int cantidad)
{
    int posicion = 0;

    for(int i = 1; i < cantidad; i++)
    {
        if(precios[i] < precios[posicion])
        {
            posicion = i;
        }
    }

    return posicion;
}

float calcularPromedio(float precios[], int cantidad)
{
    return calcularTotal(precios, cantidad) / cantidad;
}

int buscarProducto(char productos[][20], int cantidad)
{
    char nombreBuscado[20];

    getchar();
    printf("Ingrese el producto a buscar: ");
    fgets(nombreBuscado, 20, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    for(int i = 0; i < cantidad; i++)
    {
        if(strcmp(nombreBuscado, productos[i]) == 0)
        {
            return i;
        }
    }

    return -1;
}
