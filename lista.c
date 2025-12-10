/* Implementação das operações */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Começa a lista vazia */
void lista_inicializar(Lista *l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

/* Diz se não tem nenhum elemento */
int lista_vazia(const Lista *l) {
    return (l->tamanho == 0);
}

/* Quantos elementos tem na lista */
int lista_tamanho(const Lista *l) {
    return l->tamanho;
}

/* Acha o nó da posição desejada (1..tamanho) */
static No *buscar_no(const Lista *l, int pos) {
    if (pos < 1 || pos > l->tamanho) return NULL;

    No *aux = l->inicio;
    for (int i = 1; i < pos; i++)
        aux = aux->prox;

    return aux;
}

/* Lê o valor de uma posição */
int lista_obter(const Lista *l, int pos, int *valor) {
    No *no = buscar_no(l, pos);
    if (!no) return 0;

    if (valor) *valor = no->valor;
    return 1;
}

/* Troca o valor de uma posição */
int lista_modificar(Lista *l, int pos, int novo_valor) {
    No *no = buscar_no(l, pos);
    if (!no) return 0;

    no->valor = novo_valor;
    return 1;
}

/* Insere um valor em qualquer posição válida */
int lista_inserir(Lista *l, int pos, int valor) {
    if (pos < 1 || pos > l->tamanho + 1) return 0;

    No *novo = malloc(sizeof(No));
    if (!novo) return 0;

    novo->valor = valor;

    /* Inserir no começo */
    if (pos == 1) {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    /* Inserir no meio ou fim */
    else {
        No *ant = buscar_no(l, pos - 1);
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    l->tamanho++;
    return 1;
}

/* Remove um elemento e devolve seu valor */
int lista_remover(Lista *l, int pos, int *valor) {
    if (pos < 1 || pos > l->tamanho) return 0;

    No *rem;

    /* Remover o primeiro */
    if (pos == 1) {
        rem = l->inicio;
        l->inicio = rem->prox;
    }
    /* Remover qualquer outro */
    else {
        No *ant = buscar_no(l, pos - 1);
        rem = ant->prox;
        ant->prox = rem->prox;
    }

    if (valor) *valor = rem->valor;
    free(rem);
    l->tamanho--;

    return 1;
}

/* Mostra os elementos da lista */
void lista_imprimir(const Lista *l) {
    printf("[");
    for (No *aux = l->inicio; aux; aux = aux->prox) {
        printf("%d", aux->valor);
        if (aux->prox) printf(" ");
    }
    printf("]\n");
}

/* Limpa toda a memória usada pela lista */
void lista_destruir(Lista *l) {
    No *aux = l->inicio;
    while (aux) {
        No *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    l->inicio = NULL;
    l->tamanho = 0;
}
