#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL; 
    return list;
}

void * firstList(List * list) {
    if(list->head == NULL || list == NULL) return NULL;
    list->current = list->head;
    return list->head->data;
}

void * nextList(List * list) 
{
    if(list == NULL || list->current == NULL || list->current->next == NULL) return NULL;
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) 
{
    if (list == NULL || list->head == NULL) return NULL;
    Node *aux = list->head;
    while(aux->next != NULL)
    {
        aux = aux->next;
    }
    list->current = aux;

    return list->current->data;
}

void * prevList(List * list) 
{
    if (list == NULL || list->head == NULL || list->current == list->head || list->current == NULL) return NULL;
    Node *aux = list->head;
    while(aux->next != list->current)
    {
        aux = aux->next;
    }
    list->current = aux;
    return list->current->data;

}

void pushFront(List * list, void * data) 
{
    Node *nuevoNodo = createNode(data);
    nuevoNodo->prev = NULL;
    nuevoNodo->next = list->head;
    if (list->head) 
        list->head->prev = nuevoNodo;
    else
        list->tail = nuevoNodo;
    list->head = nuevoNodo;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
    
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}