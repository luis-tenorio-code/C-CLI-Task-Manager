#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../include/func-crud.h"
#include "validations.c"

#define MAX_TASKS 100

Task taskList[MAX_TASKS];
int numTasks = 0;

void createTask(const char *title, const char *description)
{
    if (numTasks < MAX_TASKS)
    {

        if (!isTitleValid(title))
        {
            printf("El título de la tarea no es válido.\n");
            return;
        }

        if (!isDescriptionValid(description))
        {
            printf("La descripción de la tarea no es válida.\n");
            return;
        }

        Task newTask;
        newTask.id = numTasks + 1;
        strcpy(newTask.title, title);
        strcpy(newTask.description, description);

        time_t now = time(0);
        strftime(newTask.createdAt, sizeof(newTask.createdAt), "%Y-%m-%d %H:%M:%S", localtime(&now));
        strcpy(newTask.updatedAt, newTask.createdAt);

        taskList[numTasks++] = newTask;
        print_success("Tarea creada correctamente.\n");
    }
    else
    {
        print_italic_red("No se pueden agregar más tareas. La lista esta llena.\n");
    }
}

void showTasks()
{
    if (numTasks == 0)
    {
        print_italic_red("No hay tareas en la lista.\n");
    }
    else
    {
        printItalic("\n\nLista de tareas:\n");
        for (int i = 0; i < numTasks; i++)
        {
            printf("---------------------------\n");
            printf("Tarea %d:\n", taskList[i].id);
            printf("Titulo: %s\n", taskList[i].title);
            printf("Descripcion: %s\n", taskList[i].description);
            printf("Creada en: %s\n", taskList[i].createdAt);
            printf("Ultima actualizacion: %s\n", taskList[i].updatedAt);
            printf("---------------------------\n\n");
        }
    }
}

void updateTask(int id, const char *title, const char *description)
{
    int index = -1;
    for (int i = 0; i < numTasks; i++)
    {
        if (taskList[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        strcpy(taskList[index].title, title);
        strcpy(taskList[index].description, description);

        time_t now = time(0);
        strftime(taskList[index].updatedAt, sizeof(taskList[index].updatedAt), "%Y-%m-%d %H:%M:%S", localtime(&now));

        print_success("Tarea actualizada correctamente.\n");
    }
    else
    {
        print_italic_red("No se encontro una tarea con el ID especificado.\n");
    }
}

void deleteTask(int id)
{
    int index = -1;
    for (int i = 0; i < numTasks; i++)
    {
        if (taskList[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < numTasks - 1; i++)
        {
            taskList[i] = taskList[i + 1];
        }
        numTasks--;
        print_success("Tarea eliminada correctamente.\n");
    }
    else
    {
        print_italic_red("No se encontro una tarea con el ID especificado.\n");
    }
}

void showTask(int id)
{
    int index = -1;

    for (int i = 0; i < numTasks; i++)
    {
        if (taskList[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        printf("\n\n---------------------------\n");
        printf("Tarea %d:\n", taskList[index].id);
        printf("Titulo: %s\n", taskList[index].title);
        printf("Descripcion: %s\n", taskList[index].description);
        printf("Creada en: %s\n", taskList[index].createdAt);
        printf("Ultima actualizacion: %s\n", taskList[index].updatedAt);
        printf("---------------------------\n\n");
    }
    else
    {
        print_italic_red("No se encontro una tarea con el ID especificado.\n");
    }
}