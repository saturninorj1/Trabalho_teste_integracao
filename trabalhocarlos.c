#include <stdio.h>
#include "trabalhocarlos.h"

int calcular_preco_unitario(int idade) {
    if (idade < 0)
        return -1;
    else if (idade <= 12)
        return 10;
    else if (idade <= 59)
        return 30;
    else
        return 15;
}

int calcular_preco_total(int idade, int quantidade) {
    if (quantidade < 1 || quantidade > 5)
        return -2;

    int preco_unitario = calcular_preco_unitario(idade);
    if (preco_unitario == -1)
        return -1;

    return preco_unitario * quantidade;
}

