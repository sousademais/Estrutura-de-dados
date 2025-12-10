/* Casos de teste que demonstram o funcionamento */

#include <stdio.h>
#include "lista.h"

/* Função simples para indicar se o teste deu certo */
void checar(const char *desc, int ok) {
    printf("%s: %s\n", desc, ok ? "OK" : "ERRO");
}

/* Testa criação e estado inicial */
void testar_inicializacao() {
    Lista l;
    lista_inicializar(&l);

    checar("Lista vazia após inicializar",
           lista_vazia(&l));

    lista_imprimir(&l);
}

/* Testa inserções em várias posições */
void testar_insercoes() {
    Lista l;
    lista_inicializar(&l);

    lista_inserir(&l, 1, 10);
    lista_inserir(&l, 2, 20);
    lista_inserir(&l, 2, 15);  // insere no meio
    lista_inserir(&l, 4, 30);  // insere no fim

    checar("Tamanho = 4", lista_tamanho(&l) == 4);
    lista_imprimir(&l);

    lista_destruir(&l);
}

/* Testa ler e modificar valores */
void testar_obter_modificar() {
    Lista l;
    lista_inicializar(&l);

    lista_inserir(&l, 1, 10);
    lista_inserir(&l, 2, 20);
    lista_inserir(&l, 3, 30);

    int v;

    lista_obter(&l, 1, &v);
    checar("Obter pos 1 = 10", v == 10);

    lista_modificar(&l, 2, 25);
    lista_obter(&l, 2, &v);
    checar("Modificar pos 2 para 25", v == 25);

    lista_imprimir(&l);
    lista_destruir(&l);
}

/* Testa remoção em diferentes posições */
void testar_remocoes() {
    Lista l;
    lista_inicializar(&l);

    lista_inserir(&l, 1, 10);
    lista_inserir(&l, 2, 20);
    lista_inserir(&l, 3, 30);

    int r;

    lista_remover(&l, 2, &r);
    checar("Removeu 20", r == 20);

    lista_remover(&l, 1, &r);
    checar("Removeu 10", r == 10);

    lista_imprimir(&l);  // deve sobrar [30]
    lista_destruir(&l);
}

int main() {
    printf("\n===== TESTES =====\n");

    testar_inicializacao();
    testar_insercoes();
    testar_obter_modificar();
    testar_remocoes();

    printf("\n===== FIM =====\n");
    return 0;
}
