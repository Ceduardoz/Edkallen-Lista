/*
Função: Registro
Autor: Davi Vidal
Data: 01/06/2025
Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do empregado
typedef struct {
    char nome[50];
    char dataNascimento[11];
    char rg[15];
    char dataAdmissao[11];
    float salario;
} Empregado;


Empregado *empregados = NULL;  
int total = 0;                 // Contador de empregados

void adicionarEmpregado() {
    // Realoca memória para mais um empregado
    empregados = realloc(empregados, (total + 1) * sizeof(Empregado));
    
    printf("\nNome: ");
    scanf(" %[^\n]", empregados[total].nome);
    printf("Data Nascimento (dd/mm/aaaa): ");
    scanf(" %[^\n]", empregados[total].dataNascimento);
    printf("RG: ");
    scanf(" %[^\n]", empregados[total].rg);
    printf("Data Admissão (dd/mm/aaaa): ");
    scanf(" %[^\n]", empregados[total].dataAdmissao);
    printf("Salário: ");
    scanf("%f", &empregados[total].salario);
    
    total++;
    printf("Empregado cadastrado!\n");
}

void listarEmpregados() {
    if (total == 0) {
        printf("Nenhum empregado cadastrado.\n");
        return;
    }
    
    for (int i = 0; i < total; i++) {
        printf("\n--- Empregado %d ---\n", i + 1);
        printf("Nome: %s\n", empregados[i].nome);
        printf("Nascimento: %s\n", empregados[i].dataNascimento);
        printf("RG: %s\n", empregados[i].rg);
        printf("Admissão: %s\n", empregados[i].dataAdmissao);
        printf("Salário: R$ %.2f\n", empregados[i].salario);
    }
}

void excluirEmpregado() {
    if (total == 0) {
        printf("Nenhum empregado para excluir.\n");
        return;
    }
    
    listarEmpregados();
    printf("\nQual empregado excluir (1-%d)? ", total);
    
    int indice;
    scanf("%d", &indice);
    
    if (indice < 1 || indice > total) {
        printf("Número inválido!\n");
        return;
    }
    
    indice--;  // Converte para índice do array
    
    // Move elementos para remover o selecionado
    for (int i = indice; i < total - 1; i++) {
        empregados[i] = empregados[i + 1];
    }
    
    total--;
    empregados = realloc(empregados, total * sizeof(Empregado));
    printf("Empregado excluído!\n");
}

int main() {
    int opcao;
    
    do {
        printf("\n=== GERENCIADOR DE EMPREGADOS ===\n");
        printf("1. Cadastrar\n2. Listar\n3. Excluir\n4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: adicionarEmpregado(); break;
            case 2: listarEmpregados(); break;
            case 3: excluirEmpregado(); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 4);
    
    free(empregados);  // Libera memória
    return 0;
}