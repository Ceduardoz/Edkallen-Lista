/*
Função: Conjectura de Goldbach com entrada do usuário
Autor: Davi Vidal
Data: 01/06/2025
Observações: 
*/

#include <stdio.h>
#include <stdbool.h>

// função para verificar se um número é primo
bool ehPrimo(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// função para encontrar e imprimir os dois primos que somam o número par
void encontrarPrimos(int num) {
    for (int i = 2; i <= num / 2; i++) {
        int j = num - i;

        if (ehPrimo(i) && ehPrimo(j)) {
            printf("%d = %d + %d\n", num, i, j);
            return;
        }
    }
    // se chegou aqui, não encontrou (seria um contra-exemplo)
    printf("%d: CONTRA-EXEMPLO ENCONTRADO!\n", num);
}

int main() {
    int N;

    printf("Digite um número inteiro maior ou igual a 2: ");
    scanf("%d", &N);

    if (N < 2) {
        printf("Erro: O número deve ser maior ou igual a 2.\n");
        return 1;
    }

    printf("\nVerificação da Conjectura de Goldbach para números pares de 4 até %d:\n", N);
    printf("========================================================================\n\n");

    int contador = 0;

    for (int num = 2; num <= N; num += 2) {
        encontrarPrimos(num);
        contador++;

        if (contador % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n========================================================================\n");
    printf("Todos os %d números pares entre 4 e %d foram verificados.\n", contador, N);
    printf("A Conjectura de Goldbach se mantém válida para todos eles (se nenhum contra-exemplo foi exibido)!\n");

    return 0;
}
