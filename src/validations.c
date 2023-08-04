#include <string.h>
#include <string.h>
#include <time.h>
#include "../include/func-crud.h"

int isTitleValid(const char *title)
{
    return title != NULL && strlen(title) > 0;
}

int isDescriptionValid(const char *description)
{
    return description != NULL && strlen(description) > 0;
}
// SEMESTRE 1 TICS
// Imprime el texto en color rojo y en cursiva
void print_italic_red(const char *text)
{
    printf("\x1B[3m\x1B[31m%s\x1B[0m", text);
}

// Imprime el texto en color verde
void print_success(const char *text)
{
    printf("\x1B[32m%s\x1B[0m", text);
}

// Imprime el texto en italica
void printItalic(const char *text)
{
    printf("\x1B[3m%s\x1B[0m", text);
}
