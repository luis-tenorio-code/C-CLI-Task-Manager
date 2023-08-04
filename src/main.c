#include <stdio.h>
#include "../include/func-crud.h"
#include "utilities.c"
#include <stdlib.h>

void options(char *choise)
{
    printBold("\n\nMenu de tareas\n");
    printf("1. Agregar tarea\n");
    printf("2. Mostrar tareas\n");
    printf("3. Actualizar tarea\n");
    printf("4. Obtener Tarea\n");
    printf("5. Eliminar tarea\n");
    printf("6. Limpiar pantalla\n");
    printf("7. Salir\n");
    printf("Ingrese su eleccion: ");
    scanf(" %c", choise);
}

int main()
{
    system("cls");
    char title[100];
    char description[500];
    int id;
    char choice;

    do
    {
        options(&choice);
        switch (choice)
        {
        case '1':
            printf("Ingrese el titulo de la tarea: ");
            scanf(" %[^\n]", title);
            printf("Ingrese la descripcion de la tarea: ");
            scanf(" %[^\n]", description);
            createTask(title, description);
            break;
        case '2':
            showTasks();
            break;
        case '3':
            printf("Ingrese el ID de la tarea a actualizar: ");
            scanf("%d", &id);
            printf("Ingrese el nuevo titulo de la tarea: ");
            scanf(" %[^\n]", title);
            printf("Ingrese la nueva descripcion de la tarea: ");
            scanf(" %[^\n]", description);
            updateTask(id, title, description);
            break;
        case '4':
            printf("Ingrese el ID de la tarea a obtener: ");
            scanf("%d", &id);
            showTask(id);
            break;
        case '5':
            printf("Ingrese el ID de la tarea a eliminar: ");
            scanf("%d", &id);
            deleteTask(id);
            break;
        case '6':
            system("cls");
            break;
        case '7':
            printf("Saliendo de la aplicacion...\n");
            break;
        default:
            printf("Opcion invalida. Por favor, elija nuevamente.\n");
            break;
        }

    } while (choice != '7');

    return 0;
}
