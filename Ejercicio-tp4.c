#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMA 100

//Estructura para las tareas.

struct
{

    int tareaID;
    char *descripcion;
    int duracion;

}typedef Tarea;

//Estructura para crear nodos.

struct
{

    Tarea T;
    //Nodo *siguiente;
    struct Nodo *siguiente;

}typedef Nodo;

//Funcion para crear nodos.

Nodo *crearNodo(int cont);

//Funcion para insertar nodos.

void insertarNodo(Nodo **start, Nodo *newNodo);

//Funcion para buscar nodo.

Nodo *buscarNodo(Nodo *start, int buscado);

//Funcion para eliminar nodo.

void eliminarNodo(Nodo **start, int dato);

//Funcion para mostrar todas las tareas.

void mostrarLista(Nodo **start);

int main(){

    int cont = 1000, opcion, opcion2, opcion3;

    Nodo *startPendientes = NULL;
    Nodo *startRealizadas = NULL;

    //Creo las tareas.

    do
    {
        Nodo *N;

        //Creo nodo.
        N = crearNodo(cont);

        //Inserto nodo.
        insertarNodo(&startPendientes, N);

        cont++;

        printf("\n Desea agregar otra tarea: \n 1)Si \n 2)No \n");
        scanf("%d", &opcion);

    } while (opcion == 1);
    
    //Paso las tareas de una lista a otra.

    do
    {
        int aux;
        Nodo *N;

        printf("\n Ingrese el ID de la tarea:");
        scanf("%d", &aux);

        //Busco la tarea en la lista 1.
        N = buscarNodo(startPendientes, aux);

        //Inserto la tarea en la lista 2.
        insertarNodo(&startRealizadas, N);

        //Elimino la tarea en la lista 1.

        eliminarNodo(&startPendientes, aux);

        printf("\n Desea buscar otra tarea: \n 1)Si \n 2)No \n");
        scanf("%d", &opcion2);

    } while (opcion2 == 1);

    //Muestro las listas.

    mostrarLista(startPendientes);
    mostrarLista(startRealizadas);
    
    //Buscar las tareas por ID o por palabras claves.

    do
    {
        int aux;
        Nodo *N;

        printf("\n Ingrese la tarea:");
        scanf("%d", &aux);

        //Busco en las pendientes.
        N = buscarNodo(startPendientes, aux);

        if (N)
        {

            printf("\n ID de la tarea: %d \n Descripcion de la tarea: %s \n Duracion de la tarea: %d", N->T.tareaID, N->T.descripcion, N->T.duracion);
            printf("\nEsta tarea aun esta pendiente.\n");

        } else
        {
            
           if (N)
           {

            //Busco en las realizadas.
            N = buscarNodo(startRealizadas, aux);

            printf("\n ID de la tarea: %d \n Descripcion de la tarea: %s \n Duracion de la tarea: %d", N->T.tareaID, N->T.descripcion, N->T.duracion);
            printf("\nEsta tarea ya fue realizada.\n");

           } else
           {
            printf("\nLa tarea seleccionada no existe. \n");
           }

        }

        printf("\n Desea buscar otra tarea: \n 1)Si \n 2)No \n");
        scanf("%d", &opcion3);

    } while (opcion3 == 1);
    



    //Libero la memoria.

    return 0;
}

//FUNCION PARA CREAR NODOS.

Nodo *crearNodo(int cont){

    Nodo *newNodo = (Nodo*)malloc(sizeof(Nodo));

    newNodo->T.tareaID = cont;

    newNodo->T.descripcion = (char*)malloc(sizeof(char));
    printf("\nIngrese la descripcion de la tarea: \n");
    scanf("%s", newNodo->T.descripcion);

    newNodo->T.duracion = 10 + rand() % 91;

    return newNodo;
}

//FUNCION PARA INSERTAR NODOS.

void insertarNodo(Nodo **start, Nodo *newNodo){

    newNodo->siguiente = *start;
    *start = newNodo;

}

//FUNCION PARA BUSCAR NODO.

Nodo *buscarNodo(Nodo *start, int buscado){

    Nodo *nodoAux = start;

    while (nodoAux && nodoAux->T.tareaID != buscado)
    {
        nodoAux = nodoAux->siguiente;
    }
    return nodoAux;
    
}

//FUNCION PARA ELIMINAR UN NODO.

void eliminarNodo(Nodo **start, int dato){

    Nodo **nodoAux = start;

    while (*nodoAux != NULL && (*nodoAux)->T.tareaID != dato)
    {
        nodoAux = &(*nodoAux)->siguiente;
    }
    
    if (*nodoAux)
    {

        Nodo *temp = *nodoAux;
        *nodoAux = (*nodoAux)->siguiente;
        free(temp);

    }
    
}

//FUNCION PARA MOSTRAR TODAS LAS LISTAS.

void mostrarLista(Nodo **start){

    Nodo *aux = start;

    while (aux != NULL)
    {
        printf("\n ID de la tarea: %d \n Descripcion de la tarea: %s \n Duracion de la tarea: %d", aux->T.tareaID, aux->T.descripcion, aux->T.duracion);

        aux = aux->siguiente;
    }
    
}