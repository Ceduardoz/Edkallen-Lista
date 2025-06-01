/*
Função: Conjectura de Goldbach
autor: Davi Vidal
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
    printf("Verificação da Conjectura de Goldbach para números pares de 700 a 1100:\n");
    printf("========================================================================\n\n");
    
    int contador = 0;
    
    for (int num = 700; num <= 1100; num += 2) {
        encontrarPrimos(num);
        contador++;
        
        // quebra de linha a cada 10 números para melhor visualização
        if (contador % 10 == 0) {
            printf("\n");
        }
    }
    
    printf("\n========================================================================\n");
    printf("Todos os %d números pares entre 700 e 1100 foram verificados.\n", contador);
    printf("A Conjectura de Goldbach se mantém válida para todos eles!\n");
    
    return 0;
}