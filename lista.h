/* Interface da TAD */

#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>

/* Cada nó guarda um número e aponta para o próximo */
typedef struct No {
    int valor;
    struct No *prox;
} No;

/* A lista guarda só o primeiro nó e quantos elementos tem */
typedef struct {
    No *inicio;
    int tamanho;
} Lista;

/* Funções básicas da lista */
void lista_inicializar(Lista *l);
int  lista_vazia(const Lista *l);
int  lista_tamanho(const Lista *l);
int  lista_obter(const Lista *l, int pos, int *valor);
int  lista_modificar(Lista *l, int pos, int novo_valor);
int  lista_inserir(Lista *l, int pos, int valor);
int  lista_remover(Lista *l, int pos, int *valor);
void lista_imprimir(const Lista *l);
void lista_destruir(Lista *l);

#endif
