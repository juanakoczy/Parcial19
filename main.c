//Defina una funcion que reciba dos listas ordenadas de numeros enteros, y retorna la lista
//que resulta de combinar las listas anteriores
#include <stdio.h>
#include "listas.h"

int main() {

    Lista * lista1 = newLista();
    Lista * lista2 = newLista();

    enlistarOrdenado(lista1, newNodo(1));
    enlistarOrdenado(lista1, newNodo(3));
    enlistarOrdenado(lista1, newNodo(4));
    enlistarOrdenado(lista1, newNodo(5));

    imprimir(lista1);
    printf("\n");

    enlistarOrdenado(lista2, newNodo(1));
    enlistarOrdenado(lista2, newNodo(2));
    enlistarOrdenado(lista2, newNodo(4));
    enlistarOrdenado(lista2, newNodo(5));
    enlistarOrdenado(lista2, newNodo(7));

    imprimir(lista2);
    printf("\n");



    imprimir(combinar(lista1, lista2));

    return 0;
}
