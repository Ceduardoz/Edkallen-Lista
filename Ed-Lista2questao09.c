/*
Função: Ordenar o vetor (bubleSort)
autor: Carlos Eduardo
Data: 31/05/2025
Observações:
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10  

// exibe o vetor
void exibirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// bubbleSort e conta os ifs e trocas
void bubbleSort(int v[], int n, int *contaIfs, int *contaTroca) {
    *contaIfs = 0;
    *contaTroca = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*contaIfs)++; // Conta o if
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*contaTroca)++; 
            }
        }
    }
}

int main() {
    int vetor[TAMANHO] = {42, 17, 8, 90, 33, 12, 5, 78, 60, 25};

    printf("Vetor original:\n");
    exibirVetor(vetor, TAMANHO);

    int totalIfs, totalTrocas;
    bubbleSort(vetor, TAMANHO, &totalIfs, &totalTrocas);

    printf("\nVetor ordenado:\n");
    exibirVetor(vetor, TAMANHO);

    printf("\nTotal de if's realizados: %d", totalIfs);
    printf("\nTotal de trocas realizadas: %d\n", totalTrocas);

    return 0;
}