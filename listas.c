//
// Created by Usuario on 9/9/2023.
//

#include "listas.h"
#include <stdio.h>
#include "malloc.h"

Nodo * newNodo (int dato){

    Nodo * aux = NULL;
    aux = malloc (sizeof(Nodo));

    if (aux == NULL){
        printf("No hay espacio de memoria suficiente.");
        exit(-1);
    }

    else{
        aux->dato = dato;
        aux->sig = NULL;
    }

    return aux;
}
Lista * newLista (){

    Lista * aux = NULL;
    aux = malloc (sizeof(Lista));

    if (aux == NULL){
        printf("No hay espacio de memoria suficiente.");
        exit(-1);
    }

    else{
        aux->cabecera = NULL;
    }

    return aux;
}

void enlistarOrdenado (Lista * lista, Nodo * nodo){

    Nodo * actual = lista->cabecera;
    Nodo * anterior = NULL;

    while (actual != NULL && actual->dato < nodo->dato){//el nuevo nodo va en el medio

        anterior = actual;
        actual = actual->sig;

    }

    if (anterior == NULL){//la lista esta vacia, el nuevo nodo es la cabecera

        nodo->sig = lista->cabecera;
        lista->cabecera = nodo;

    }

    else{//el nuevo nodo es consecutivo al anterior
        anterior->sig= nodo;
        nodo->sig = actual;
    }

}
void imprimir (Lista * lista){

    Nodo * aux= lista->cabecera;

    while(aux != NULL){

        printf("%d", aux->dato);
        aux= aux->sig;

    }
}

Lista *combinar(Lista *lista1, Lista *lista2) {

    Nodo *aux1 = lista1->cabecera;
    Nodo *aux2 = lista2->cabecera;

    Lista *resultado = newLista();

    while (aux1 != NULL && aux2 != NULL) {//recorro las dos litas

        if (aux1->dato < aux2->dato) {//si el dato de l1 es menor a l2, no esta en l2, lo agrego l1
            enlistarOrdenado(resultado, newNodo(aux1->dato));
            aux1 = aux1->sig;//avanzo l1
        } else if (aux1->dato > aux2->dato) {//si el dato l1 es mayor a l2, no esta en l1, agrego l2
            enlistarOrdenado(resultado, newNodo(aux2->dato));
            aux2 = aux2->sig;//avanzo l2
        } else {// los datos son iguales, agrego de una lista y avanzo las dos
            enlistarOrdenado(resultado, newNodo(aux1->dato));
            aux1 = aux1->sig;
            aux2 = aux2->sig;
        }
    }
        while (aux1!= NULL){//agrego todo lo que falta de l1
            enlistarOrdenado(resultado,newNodo(aux1->dato));
            aux1 = aux1->sig;
        }
        while (aux2!= NULL){//agrego todo lo  falta de l2
            enlistarOrdenado(resultado,newNodo(aux2->dato));
            aux2 = aux2->sig;
        }

    return resultado;
}