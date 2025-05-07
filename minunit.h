#ifndef MINUNIT_H
#define MINUNIT_H

#include <stdio.h>

int tests_run;

/* Macro para verificar uma condição; retorna a linha se falhar */
#define mu_check(test) do { if (!(test)) return __LINE__; } while (0)

/* Define a função de teste como void e estática */
#define MU_TEST(name) static const char *name(void)

/* Executa o teste e incrementa o contador */
#define MU_RUN_TEST(test) do { \
    const char *message = test(); \
    tests_run++; \
    if (message) return message; \
} while (0)

/* Cria uma suíte de testes */
#define MU_TEST_SUITE(name) static const char *name(void)

/* Roda a suíte e imprime os resultados */
#define MU_RUN_SUITE(suite) do { \
    const char *result = suite(); \
    if (result != 0) { \
        printf("Teste falhou: %s\n", result); \
        return 1; \
    } \
} while (0)

/* Imprime o relatório final */
#define MU_REPORT() printf("Todos os testes passaram (%d executados)\n", tests_run)

#endif

