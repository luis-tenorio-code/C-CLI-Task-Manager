#ifndef FUNC_CRUD_H
#define FUNC_CRUD_H

typedef struct
{
    int id;
    char title[100];
    char description[500];
    char createdAt[20];
    char updatedAt[20];
} Task;

void createTask(const char *title, const char *description);
void showTasks();
void updateTask(int id, const char *title, const char *description);
void deleteTask(int id);
void showTask(int id);

#endif

/*
Los símbolos # que aparecen al principio de las líneas #ifndef,
#define y #endif son directivas del preprocesador en C.

Estas directivas se utilizan para evitar que el compilador
incluya varias veces el mismo archivo de encabezado (header file) en un programa.

La directiva #ifndef significa "if not defined" y se utiliza
para comprobar si una macro o símbolo ya ha sido definido.
Si no ha sido definido, se define utilizando la directiva #define.

La directiva #endif simplemente indica el final de la sección condicional.
*/