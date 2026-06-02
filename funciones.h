#ifndef INVENTARIO_H
#define INVENTARIO_H

int menu();
void Nombre_Productos(char nombres[][20], int n);
void Precios(float precio[], int n);
float precio_total(float precio[],int n);
int mayor(float precio[], int n);
int menor(float precio[], int n);
float promedio(float precio[], int n);
int encontrar_producto(char nombres[][20], int n);

#endif
