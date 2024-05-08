//
// Created by MarioMang on 2024/5/8.
//

#ifndef DS_DOUBLE_LINKED_LIST_H
#define DS_DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

typedef struct double_linked_list {
    size_t length;
    Node *head;
    Node *tail;
}DLL;


DLL *dll_new();

void dll_insert_head(DLL *dll, int element);

void dll_insert_tail(DLL *dll, int element);

void dll_insert(DLL *dll, size_t index, int element);

int dll_get(DLL *dll, size_t index);

void dll_reverse(DLL *dll);

void dll_replace(DLL *dll, size_t index, int element);

int dll_remove(DLL *dll, size_t index);

void dll_free(DLL *dll);

void dll_print(DLL *dll);


#endif //DS_DOUBLE_LINKED_LIST_H
