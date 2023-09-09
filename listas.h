//
// Created by Usuario on 9/9/2023.
//

#ifndef PARCIAL19_LISTAS_H
#define PARCIAL19_LISTAS_H

typedef struct nodo{

    int dato;
    struct nodo * sig;

}Nodo;

typedef struct lista{

    Nodo * cabecera;

}Lista;

Nodo * newNodo (int dato);
Lista * newLista ();
void enlistarOrdenado (Lista * lista, Nodo * newNodo);
void imprimir (Lista * lista);
Lista * combinar (Lista * lista1, Lista * lista2);

#endif //PARCIAL19_LISTAS_H
