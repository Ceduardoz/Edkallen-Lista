/*
Função: Raiz Quadrada
autor: Davi Vidal
Data: 01/06/2025
Observações:  
*/


#include <stdio.h>
#include <math.h>

double raizQuadrada(double n) {
    double x = n / 2.0; 
    double precisao = 0.0001;
    
    while (fabs(x * x - n) > precisao) {
        x = 0.5 * (x + n / x);
    }
    
    return x;
}

int main() {
    double numero;

    printf("Digite um número positivo para calcular a raiz quadrada: ");
    scanf("%lf", &numero);

    if (numero < 0) {
        printf("Não é possível calcular a raiz quadrada de um número negativo.\n");
    } else {
        double resultado = raizQuadrada(numero);
        printf("A raiz quadrada aproximada de %.4lf é %.5lf\n", numero, resultado);
    }

    return 0;
}