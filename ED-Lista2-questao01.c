/*
Função: Lista Crescente
autor: Carlos Eduardo
Data: 29/05/2025
Observações:  
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

// selectionSort
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

// exibe a lista
void exibeLista(int lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int lista[TAMANHO] = {14, 58, 76, 0, 7, 4, 22, 44, 36, 69};

    printf("Lista original:\n");
    exibeLista(lista, TAMANHO);

    selectionSort(lista, TAMANHO);

    printf("Lista ordenada:\n");
    exibeLista(lista, TAMANHO);

    return 0;
}
