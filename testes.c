#include "minunit.h"
#include "zoologico.h"

// Testa preço para criança (idade < 12)
MU_TEST(test_crianca) {
    mu_check(calcular_preco_total(5, 2) == 20);
}

// Testa preço para adulto (idade entre 12 e 59)
MU_TEST(test_adulto) {
    mu_check(calcular_preco_total(30, 1) == 30);
}

// Testa preço para idoso (idade >= 60)
MU_TEST(test_idoso) {
    mu_check(calcular_preco_total(65, 4) == 60);
}

// Testa caso com quantidade zero
MU_TEST(test_qtd_zero) {
    mu_check(calcular_preco_total(20, 0) == -1);
}

// Testa caso com quantidade negativa
MU_TEST(test_qtd_negativa) {
    mu_check(calcular_preco_total(20, -1) == -1);
}

// Testa caso com idade negativa (tratado como criança)
MU_TEST(test_idade_negativa) {
    mu_check(calcular_preco_total(-5, 2) == 20);
}

// Testa caso com idade extrema (tratado como idoso)
MU_TEST(test_idade_extrema) {
    mu_check(calcular_preco_total(150, 1) == 15);
}

// Testa preço com grande quantidade válida
MU_TEST(test_qtd_maior_que_5) {
    mu_check(calcular_preco_total(20, 6) != -1);
}

// Agrupa todos os testes acima
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_crianca);
    MU_RUN_TEST(test_adulto);
    MU_RUN_TEST(test_idoso);
    MU_RUN_TEST(test_qtd_zero);
    MU_RUN_TEST(test_qtd_negativa);
    MU_RUN_TEST(test_idade_negativa);
    MU_RUN_TEST(test_idade_extrema);
    MU_RUN_TEST(test_qtd_maior_que_5);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}

