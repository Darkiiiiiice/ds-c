//
// Created by MarioMang on 2024/4/16.
//

#ifndef DS_SINGLE_LINKED_LIST_H
#define DS_SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct single_linked_list {
    Node *head;
    size_t length;
} SLL;


SLL *sll_new();

void sll_insert_head(SLL *sll, int element);

void sll_insert_tail(SLL *sll, int element);

void sll_insert(SLL *sll, size_t index, int element);

int sll_get(SLL *sll, size_t index);

void sll_reverse(SLL *sll);

void sll_replace(SLL *sll, size_t index, int element);

int sll_remove(SLL *sll, size_t index);

void sll_free(SLL *sll);

void sll_print(SLL *sll);

#endif //DS_SINGLE_LINKED_LIST_H
