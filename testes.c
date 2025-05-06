#include "minunit.h"
#include "trabalhocarlos.h"

// Teste para criança: idade 5, quantidade 2 -> 2 * 10 = 20
MU_TEST(test_crianca) {
    mu_check(calcular_preco_total(5, 2) == 20);
}

// Teste para adulto: idade 30, quantidade 1 -> 1 * 30 = 30
MU_TEST(test_adulto) {
    mu_check(calcular_preco_total(30, 1) == 30);
}

// Teste para idoso: idade 65, quantidade 4 -> 4 * 15 = 60
MU_TEST(test_idoso) {
    mu_check(calcular_preco_total(65, 4) == 60);
}

// Teste para quantidade zero: deve retornar erro (-1)
MU_TEST(test_qtd_zero) {
    mu_check(calcular_preco_total(20, 0) == -1);
}

// Teste para quantidade maior que 5: deve retornar erro (-1)
MU_TEST(test_qtd_maior_que_5) {
    mu_check(calcular_preco_total(20, 6) == -1);
}

// Teste para idade negativa: deve ser tratado como criança
MU_TEST(test_idade_negativa) {
    mu_check(calcular_preco_total(-5, 2) == 20);
}

// Teste para idade extrema (ex: 150 anos): deve ser tratado como idoso
MU_TEST(test_idade_extrema) {
    mu_check(calcular_preco_total(150, 1) == 15);
}

// Teste para quantidade negativa: deve retornar erro (-1)
MU_TEST(test_qtd_negativa) {
    mu_check(calcular_preco_total(20, -1) == -1);
}

// Agrupando todos os testes
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_crianca);
    MU_RUN_TEST(test_adulto);
    MU_RUN_TEST(test_idoso);
    MU_RUN_TEST(test_qtd_zero);
    MU_RUN_TEST(test_qtd_maior_que_5);
    MU_RUN_TEST(test_idade_negativa);
    MU_RUN_TEST(test_idade_extrema);
    MU_RUN_TEST(test_qtd_negativa);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}

