
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no {
    int valor;
    struct no* prox;
} No;

struct lista {
    No* cabeca;
};

Lista* criarLista(void) {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista == NULL) {
        return NULL; 
    }
    lista->cabeca = NULL; 
    return lista;
}

int inserir(Lista* lista, int valor) {
    if (lista == NULL) {
        return 0; 
    }

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        return 0; 
    }

    novo->valor = valor;

    novo->prox = lista->cabeca;

    lista->cabeca = novo;

    return 1; 
}

int remover(Lista* lista, int valor) {
    if (lista == NULL || lista->cabeca == NULL) {
        return 0;
    }

    No* atual = lista->cabeca;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                
                lista->cabeca = atual->prox;
            } else {
                
                anterior->prox = atual->prox;
            }
            free(atual);
            return 1; 
        }
        anterior = atual;
        atual = atual->prox;
    }

    return 0; 
}

int buscar(Lista* lista, int valor) {
    if (lista == NULL) {
        return 0;
    }

    No* atual = lista->cabeca;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; 
        }
        atual = atual->prox;
    }

    return 0;
}

void destruirLista(Lista* lista) {
    if (lista == NULL) {
        return;
    }

    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    free(lista);
}