#include <stdio.h>
#include "lista.h"
#include <windows.h>

int main(void) {
    SetConsoleOutputCP(CP_UTF8);

    Lista* lista = criarLista();
    
    if (lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    printf("Inserindo valores: 10, 20, 30\n");
    inserir(lista, 10);
    inserir(lista, 20);
    inserir(lista, 30);
    inserir(lista, 100);

    printf("Buscando 20: %s\n", buscar(lista, 20) ? "encontrado" : "não encontrado");
    printf("Buscando 99: %s\n", buscar(lista, 99) ? "encontrado" : "não encontrado");
    printf("Buscando 100: %s\n", buscar(lista, 100) ? "encontrado" : "não encontrado");

    printf("Removendo 20...\n");
    remover(lista, 20);
    printf("Buscando 20 novamente: %s\n", buscar(lista, 20) ? "encontrado" : "não encontrado");

    destruirLista(lista);
    printf("Lista destruída. Teste finalizado.\n");

    return 0;
}