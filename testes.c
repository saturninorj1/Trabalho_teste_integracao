
#include "minunit.h"
#include "trabalhocarlos.h"

// Testa criança com idade válida e 2 bilhetes (esperado: R$20)
MU_TEST(test_crianca_valida) {
    mu_check(calcular_preco_total(10, 2) == 20);
}

// Testa adulto com 1 bilhete (esperado: R$30)
MU_TEST(test_adulto_valido) {
    mu_check(calcular_preco_total(30, 1) == 30);
}

// Testa idoso com 3 bilhetes (esperado: R$45)
MU_TEST(test_idoso_valido) {
    mu_check(calcular_preco_total(70, 3) == 45);
}

// Testa idade negativa (erro esperado: -1)
MU_TEST(test_idade_invalida_negativa) {
    mu_check(calcular_preco_total(-5, 2) == -1);
}

// Testa quantidade maior que o permitido (erro esperado: -2)
MU_TEST(test_qtd_muito_alta) {
    mu_check(calcular_preco_total(25, 6) == -2);
}

// Testa quantidade igual a 0 (erro esperado: -2)
MU_TEST(test_qtd_zero) {
    mu_check(calcular_preco_total(25, 0) == -2);
}

// Testa limite superior da faixa de criança (12 anos, esperado: R$10)
MU_TEST(test_limite_superior_idade_crianca) {
    mu_check(calcular_preco_total(12, 1) == 10);
}

// Testa início da faixa de adulto (13 anos, esperado: R$30)
MU_TEST(test_limite_inferior_idade_adulto) {
    mu_check(calcular_preco_total(13, 1) == 30);
}

// Testa fim da faixa de adulto (59 anos, esperado: R$30)
MU_TEST(test_limite_superior_idade_adulto) {
    mu_check(calcular_preco_total(59, 1) == 30);
}

// Testa início da faixa de idoso (60 anos, esperado: R$15)
MU_TEST(test_limite_inferior_idade_idoso) {
    mu_check(calcular_preco_total(60, 1) == 15);
}

// Conjunto de todos os testes
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_crianca_valida);
    MU_RUN_TEST(test_adulto_valido);
    MU_RUN_TEST(test_idoso_valido);
    MU_RUN_TEST(test_idade_invalida_negativa);
    MU_RUN_TEST(test_qtd_muito_alta);
    MU_RUN_TEST(test_qtd_zero);
    MU_RUN_TEST(test_limite_superior_idade_crianca);
    MU_RUN_TEST(test_limite_inferior_idade_adulto);
    MU_RUN_TEST(test_limite_superior_idade_adulto);
    MU_RUN_TEST(test_limite_inferior_idade_idoso);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
