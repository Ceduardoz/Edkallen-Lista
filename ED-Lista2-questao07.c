#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// quickSort
void quickSort(int v[], int inicio, int fim){
    int i = inicio;
    int j = fim;
    int meio = (i + j) / 2;
    int m = v[meio];

    while (i <= j){
        while(v[i] < m) i++;
        while(v[j] > m) j--;

        if(i <= j){
            int troca = v[i];
            v[i] = v[j];
            v[j] = troca;
            i++;
            j--;
        }
    }

    if(inicio < j) quickSort(v, inicio, j);
    if(i < fim) quickSort(v, i, fim);
}
// exibe o vetor
void exibeVetor(int v[]){
    printf("[");
    for (int i = 0; i < MAX; i++){
        printf("%d, ", v[i]);
    }
    printf("]");
    printf("\n");
}

int main(){
    int v[MAX] = {6, 22, 10, 34, 32, 89, 56, 44, 69, 70};
    
    printf("\nO primeiro elemento = %d \nO ultimo = %d", v[0], v[MAX-1]);

    printf("\n=======================\n");

    printf("Vetor Original: ");
    exibeVetor(v);

    quickSort(v, 0, MAX - 1);

    printf("Vetor Ordenado: ");
    exibeVetor(v);

    return 0;
}
