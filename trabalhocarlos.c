#include <stdio.h>

// Função que retorna o preço do bilhete baseado na idade do visitante
int calcular_preco_unitario(int idade) {
    if (idade < 0)
        return -1; // Erro: idade inválida
    else if (idade <= 12)
        return 10; // Crianças até 12 anos
    else if (idade <= 59)
        return 30; // Adultos entre 13 e 59 anos
    else
        return 15; // Idosos com 60 anos ou mais
}

// Função que calcula o preço total com base na idade e quantidade
int calcular_preco_total(int idade, int quantidade) {
    if (quantidade < 1 || quantidade > 5)
        return -2; // Erro: quantidade inválida

    int preco_unitario = calcular_preco_unitario(idade);
    if (preco_unitario == -1)
        return -1; // Erro: idade inválida

    return preco_unitario * quantidade;
}

// Função principal interativa
int main() {
    int idade, quantidade;

    printf("Informe a idade do visitante: ");
    scanf("%d", &idade);

    printf("Informe a quantidade de bilhetes (máximo 5): ");
    scanf("%d", &quantidade);

    int total = calcular_preco_total(idade, quantidade);

    if (total == -1) {
        printf("Erro: Idade inválida.\n");
    } else if (total == -2) {
        printf("Erro: A quantidade de bilhetes deve estar entre 1 e 5.\n");
    } else {
        printf("Preço total a pagar: R$%d\n", total);
    }

    return 0;
}

