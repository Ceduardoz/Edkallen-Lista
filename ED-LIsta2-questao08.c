/*
Função: TAD
autor: Davi Vidal
Data: 01/06/2025
Observações:  
*/


#include <stdio.h>
#include <stdlib.h>

// estrutura do número complexo
typedef struct {
    double real, imag;
} Complexo;

// criar número complexo
Complexo* criar(double r, double i) {
    Complexo* c = malloc(sizeof(Complexo));
    if (!c) return NULL;
    c->real = r;
    c->imag = i;
    return c;
}

// destruir número complexo
void destruir(Complexo* c) {
    free(c);
}

// ler número complexo
Complexo* ler() {
    double r, i;
    printf("Real: ");
    scanf("%lf", &r);
    printf("Imaginário: ");
    scanf("%lf", &i);
    return criar(r, i);
}

// somar
Complexo* somar(Complexo* a, Complexo* b) {
    return criar(a->real + b->real, a->imag + b->imag);
}

// subtrair
Complexo* subtrair(Complexo* a, Complexo* b) {
    return criar(a->real - b->real, a->imag - b->imag);
}

// multiplicar
Complexo* multiplicar(Complexo* a, Complexo* b) {
    return criar(a->real * b->real - a->imag * b->imag,
                 a->real * b->imag + a->imag * b->real);
}

// dividir
Complexo* dividir(Complexo* a, Complexo* b) {
    double denom = b->real * b->real + b->imag * b->imag;
    if (denom == 0) return NULL;
    return criar((a->real * b->real + a->imag * b->imag) / denom,
                 (a->imag * b->real - a->real * b->imag) / denom);
}

// mostrar
void mostrar(Complexo* c) {
    printf("(%.6f,%.6f)\n", c->real, c->imag);
}

// exemplo de uso
int main() {
    printf("=== TAD Complexo ===\n");
    
    // criar números
    Complexo* c1 = criar(3.0, 4.0);
    Complexo* c2 = criar(1.0, -2.0);
    
    printf("c1 = "); mostrar(c1);
    printf("c2 = "); mostrar(c2);
    
    // operações
    Complexo* soma = somar(c1, c2);
    Complexo* sub = subtrair(c1, c2);
    Complexo* mult = multiplicar(c1, c2);
    Complexo* div = dividir(c1, c2);
    
    printf("\nResultados:\n");
    printf("Soma:          "); mostrar(soma);
    printf("Subtração:     "); mostrar(sub);
    printf("Multiplicação: "); mostrar(mult);
    printf("Divisão:       "); mostrar(div);
    
    // teste com entrada do usuário
    printf("\nDigite um número complexo:\n");
    Complexo* user = ler();
    printf("Você digitou: "); mostrar(user);
    
    // liberar memória
    destruir(c1); destruir(c2); destruir(soma); 
    destruir(sub); destruir(mult); destruir(div); destruir(user);
    
    return 0;
}