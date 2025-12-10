# Estrutura-de-dados
Atividade prática 2 

*Utilizei IA nesta parte do read.me para ser mais didático - confesso que tenho uma defasagem na organização dessa parte - para o senhor ler e entender melhor as partes dos códigos, além dos comentários servindo como explicações do que coloquei nos códigos e a motivação das funcionalidades aplicadas.

````markdown
# Lista Encadeada de Inteiros em C

Este repositório contém a implementação de uma **lista encadeada simples de inteiros**, utilizando **alocação dinâmica de memória**, conforme solicitado na atividade da disciplina.

A implementação está organizada como uma TAD (Tipo Abstrato de Dados) e acompanhada de casos de teste que demonstram o funcionamento das operações.

---

## 1. Estrutura do Projeto

Arquivos principais:

- `lista.h` – definição das estruturas e da interface da lista encadeada  
- `lista.c` – implementação das operações da lista  
- `main.c` – casos de teste das operações implementadas  

Organização sugerida do repositório:

```text
.
├─ lista.h
├─ lista.c
└─ main.c
````

---

## 2. Especificação da Lista Encadeada

A lista é composta por nós encadeados, cada um contendo:

* um valor inteiro (`int valor`)
* um ponteiro para o próximo nó na lista (`struct No *prox`)

Além disso, há uma estrutura de controle da lista:

* ponteiro para o primeiro nó (`No *inicio`)
* tamanho atual da lista (`int tamanho`)

As **posições válidas** na lista são numeradas a partir de **1 até o tamanho da lista**.
Por exemplo, se a lista tem 3 elementos, as posições válidas são: 1, 2 e 3.

---

## 3. Operações Implementadas

Foram implementadas as seguintes operações:

1. **Criação da lista vazia**

   ```c
   void lista_inicializar(Lista *l);
   ```

2. **Verificar se a lista está vazia**

   ```c
   int lista_vazia(const Lista *l);
   ```

3. **Obter o tamanho da lista**

   ```c
   int lista_tamanho(const Lista *l);
   ```

4. **Obter o valor de uma determinada posição**

   ```c
   int lista_obter(const Lista *l, int pos, int *valor);
   ```

5. **Modificar o valor de uma determinada posição**

   ```c
   int lista_modificar(Lista *l, int pos, int novo_valor);
   ```

6. **Inserir um elemento em uma determinada posição**

   ```c
   int lista_inserir(Lista *l, int pos, int valor);
   ```

   * Posições válidas: `1` até `tamanho + 1`
   * Exemplo:

     * `pos == 1` → insere no início
     * `pos == tamanho + 1` → insere no final

7. **Retirar (remover) um elemento de uma determinada posição**

   ```c
   int lista_remover(Lista *l, int pos, int *valor);
   ```

8. **Imprimir todos os elementos da lista**

   ```c
   void lista_imprimir(const Lista *l);
   ```

9. **Liberar toda a memória utilizada pela lista**

   ```c
   void lista_destruir(Lista *l);
   ```

---

## 4. Casos de Teste (`main.c`)

O arquivo `main.c` contém funções de teste que exercitam as operações da lista de forma simples e direta.
Entre os cenários testados, estão:

* **Inicialização** e verificação de lista vazia
* **Inserções**:

  * em lista vazia
  * no início, no meio e no fim
* **Leitura e modificação** de valores por posição
* **Remoção** de elementos:

  * do meio
  * do início
  * até restar apenas um elemento
* Impressão do conteúdo da lista em diferentes momentos

Esses testes permitem verificar visualmente se as operações foram implementadas corretamente.

---

## 5. Como Compilar

No terminal, dentro da pasta do projeto, execute:

```bash
gcc lista.c main.c -o lista_test
```

Opcionalmente, pode-se adicionar flags de compilação mais estritas:

```bash
gcc -Wall -Wextra -std=c11 lista.c main.c -o lista_test
```

---

## 6. Como Executar

Após a compilação:

```bash
./lista_test
```

A saída exibirá os testes sendo realizados e mensagens indicando se os resultados foram os esperados.

---

## 7. Exemplo de Saída Esperada (Resumo)

Um exemplo simplificado da saída do programa pode ser:

```text
===== TESTES =====
Lista vazia após inicializar: OK
[]

Tamanho = 4: OK
[10 15 20 30]

Obter pos 1 = 10: OK
Modificar pos 2 para 25: OK
[10 25 30]

Removeu 20: OK
Removeu 10: OK
[30]

===== FIM =====
```

Isso ilustra a criação, inserção, leitura, modificação, remoção e impressão dos elementos da lista.


