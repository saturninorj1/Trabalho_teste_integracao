#include "minunit.h"
#include "trabalhocarlos.h"

int tests_run = 0;

MU_TEST(test_crianca) {
    mu_check(calcular_preco_total(5, 2) == 20);
}

MU_TEST(test_adulto) {
    mu_check(calcular_preco_total(30, 1) == 30);
}

MU_TEST(test_idoso) {
    mu_check(calcular_preco_total(65, 4) == 60);
}

MU_TEST(test_qtd_zero) {
    mu_check(calcular_preco_total(20, 0) == -2);
}

MU_TEST(test_qtd_maior_que_5) {
    mu_check(calcular_preco_total(20, 6) == -2);
}

MU_TEST(test_idade_negativa) {
    mu_check(calcular_preco_total(-5, 2) == -1);
}

MU_TEST(test_idade_extrema) {
    mu_check(calcular_preco_total(150, 1) == 15);
}

MU_TEST(test_qtd_negativa) {
    mu_check(calcular_preco_total(20, -1) == -2);
}

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

