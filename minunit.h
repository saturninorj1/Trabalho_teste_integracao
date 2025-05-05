/* minunit.h - Framework mínimo para testes unitários em C */

#ifndef MINUNIT_H
#define MINUNIT_H

#include <stdio.h>

/* Armazena a quantidade de testes executados */
int tests_run;

/* Macro para verificar uma condição; retorna a mensagem se falhar */
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)

/* Macro para executar um teste */
#define mu_run_test(test) do { \
    const char *message = test(); \
    tests_run++; \
    if (message) return message; \
} while (0)

/* Função padrão para relatar o resultado dos testes */
static inline void mu_report() {
    if (tests_run == 0) {
        printf("Nenhum teste foi executado!\n");
    } else {
        printf("Todos os %d testes passaram com sucesso.\n", tests_run);
    }
}

#endif /* MINUNIT_H */
