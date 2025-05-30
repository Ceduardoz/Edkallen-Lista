/*
Função: Aeroporto
autor: Carlos Eduardo
Data: 29/05/2025
Observações: utilizado o ChatGPT para aprender como usar ** para percorrer uma vetor de ponteiros 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGLA 4
#define MAX_CIDADE 51
#define MAX_PAIS 31

// Estrutura
typedef struct {
    char sigla[MAX_SIGLA];
    char cidade[MAX_CIDADE];
    char pais[MAX_PAIS];
    float taxa;
    int capacidade;
} Aeroporto;

Aeroporto **aeroportos = NULL;
int totalAeroportos = 0;

// Ler as informações
void lerAeroporto(Aeroporto *a) {
    printf("Sigla (3 letras): ");
    scanf(" %3s", a->sigla);

    printf("Cidade: ");
    scanf(" %s50[^\n]", a->cidade);

    printf("Pais: ");
    scanf(" %s30[^\n]", a->pais);

    printf("Taxa: ");
    scanf("%f", &a->taxa);

    printf("Capacidade: ");
    scanf("%d", &a->capacidade);
}

// exibir todos os aeroportos
void exibirAeroporto(Aeroporto *a) {
    printf("\nSigla: %s\nCidade: %s\nPaís: %s\nTaxa: %.2f\nCapacidade: %d\n",
           a->sigla, a->cidade, a->pais, a->taxa, a->capacidade);
}

// excluir algum aeroporto pelo indice
void excluirAeroporto(Aeroporto **aeroportos, int *total, int indice) {
    if (indice < 0 || indice >= *total) {
        printf("Índice inválido!\n");
        return;
    }

    free(aeroportos[indice]);

    for (int i = indice; i < *total - 1; i++) {
        aeroportos[i] = aeroportos[i + 1];
    }

    (*total)--;
}

int main() {
    int opcao;
    Aeroporto **aeroportos = NULL;
    int totalAeroportos = 0;

    do {
        printf("\n1 - Adicionar aeroporto\n2 - Listar aeroportos\n3 - Excluir aeroporto\n0 - Sair\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Aeroporto *novo = (Aeroporto *) malloc(sizeof(Aeroporto));
                if (novo == NULL) {
                    printf("Erro de alocacao!\n");
                    break;
                }

                getchar();
                lerAeroporto(novo);

                aeroportos = (Aeroporto **) realloc(aeroportos, (totalAeroportos + 1) * sizeof(Aeroporto *));
                if (aeroportos == NULL) {
                    printf("Erro ao realocar!\n");
                    break;
                }

                aeroportos[totalAeroportos++] = novo;
                break;
            }

            case 2:
                for (int i = 0; i < totalAeroportos; i++) {
                    printf("\nAeroporto [%d]:\n", i);
                    exibirAeroporto(aeroportos[i]);
                }
                break;

            case 3: {
                int indice;
                printf("Informe o indice do aeroporto a excluir: ");
                scanf("%d", &indice);
                excluirAeroporto(aeroportos, &totalAeroportos, indice);
                aeroportos = realloc(aeroportos, totalAeroportos * sizeof(Aeroporto *));
                break;
            }

            case 0:
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    for (int i = 0; i < totalAeroportos; i++) {
        free(aeroportos[i]);
    }
    free(aeroportos);

    return 0;
}
