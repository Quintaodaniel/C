#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cap;
    int f, r;
    int* vetor;
} Fila;

Fila* criaFila(int cap) {
    Fila* q = (Fila*) malloc(sizeof(Fila));

    if (!q) {
        puts("Erro ao alocar memória para a Fila!");
        exit(1);
    }

    q->f = -1; 
    q->r = -1; 
    q->cap = cap;
    q->vetor = (int*) malloc(cap * sizeof(int));

    if (!q->vetor) {
        puts("Erro ao alocar memória para o vetor da Fila!");
        free(q);
        exit(1);
    }

    return q;
}

void esvazia(Fila* q) {
    q->f = -1;
    q->r = -1;
}

int vazia(const Fila* q) {
    return (q->f == -1);
}

int cheia(const Fila* q) {
    return ((q->r + 1) % q->cap == q->f);
}

void enfila(Fila* q, int num) {
    if (cheia(q)) {
        puts("Erro: A fila está cheia!");
        return;
    }

    if (vazia(q)) {
        q->f = 0;
    }

    q->r = (q->r + 1) % q->cap;
    q->vetor[q->r] = num;
}

int desenfila(Fila* q) {
    if (vazia(q)) {
        puts("Erro: A fila está vazia!");
        exit(1); 
    }

    int num = q->vetor[q->f];

    if (q->f == q->r) {
        esvazia(q); 
    } else {
        q->f = (q->f + 1) % q->cap;
    }

    return num;
}

int frente(const Fila* q) {
    if (vazia(q)) {
        puts("Erro: A fila está vazia!");
        exit(1);
    }
    return q->vetor[q->f];
}

void destruirFila(Fila* q) {
    if (q != NULL) {
        free(q->vetor);
        free(q);
    }
}