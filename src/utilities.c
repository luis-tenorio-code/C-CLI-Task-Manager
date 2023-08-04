#include <stdio.h>

// Función para imprimir texto en negrita (bold) en la consola
void printBold(const char *text)
{
    printf("\033[1m%s\033[0m", text);
}
