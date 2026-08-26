#ifndef LISTA_H
#define LISTA_H

typedef struct lista Lista;

// Estrutura do nó da lista
Lista* criarLista();

// Função para inserir um valor na lista
int inserir(Lista* lista, int valor);

// Função para remover um valor da lista
int remover(Lista* lista, int valor);

// Função para buscar um valor na lista
int buscar(Lista* lista, int valor);

// Função para destruir a lista e liberar a memória alocada
void destruirLista(Lista* lista); 

#endif // LISTA_H