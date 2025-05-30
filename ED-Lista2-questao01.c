/*
Função: Lista Crescente
autor: Carlos Eduardo
Data: 29/05/2025
Observações:  
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

// Função para organizar a lista
void selectionSort(int lista[], int tamanho) {
    int i, menorValor, troca;
    int k = 0;

    while(k < tamanho){
        int menor = 99999999;
        for (i = k; i < tamanho; i++){
            if (lista[i] < menor){
                menor = lista[i];
                menorValor = i;
            }
        }   
        troca = lista[k];
        lista[k] = lista[menorValor];
        lista[menorValor] = troca;

        k++;
    }
}

// Função para imprimir a lista
void imprimirlista(int lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int lista[TAMANHO];
    srand(time(NULL));

    lista[0] = 43;
    lista[1] = 55;
    lista[2] = 22;
    lista[3] = 666;
    lista[4] = 14;
    lista[5] = 4;
    lista[6] = 6;
    lista[7] = 37;
    lista[8] = 56;
    lista[9] = 64;

    printf("Lista original:\n");
    imprimirlista(lista, TAMANHO);

    selectionSort(lista, TAMANHO);

    printf("Lista ordenada:\n");
    imprimirlista(lista, TAMANHO);

    return 0;
}
