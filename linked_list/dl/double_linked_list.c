//
// Created by MarioMang on 2024/5/8.
//

#include "double_linked_list.h"


DLL *dll_new() {
    DLL *dll = malloc(sizeof(DLL));
    dll->head = NULL;
    dll->tail = NULL;
    dll->length = 0;
    return dll;
}

void dll_insert_head(DLL *dll, int element) {
    Node *elem = malloc(sizeof(Node));
    elem->data = element;
    elem->prev = NULL;
    elem->next = NULL;

    if (dll->head == NULL) {
        dll->head = elem;
        dll->tail = elem;

    } else {

        Node *tmp = dll->head;
        elem->prev = NULL;
        elem->next = tmp;
        tmp->prev = elem;

        dll->head = elem;
    }
    dll->length++;
}

void dll_insert_tail(DLL *dll, int element) {
    Node *elem = malloc(sizeof(Node));
    elem->data = element;
    elem->prev = NULL;
    elem->next = NULL;

    if (dll->tail == NULL) {
        dll->head = elem;
        dll->tail = elem;
    } else {
        Node *tmp = dll->tail;
        elem->prev = tmp;
        elem->next = NULL;
        tmp->next = elem;

        dll->tail = elem;
    }
    dll->length++;
}

void dll_insert(DLL *dll, size_t index, int element) {
    if (index <= 0) {
        return dll_insert_head(dll, element);
    }
    if (index >= dll->length) {
        return dll_insert_tail(dll, element);
    }

    Node *cur = dll->head;
    for (size_t i = 1; i < index; i++) {
        cur = cur->next;
    }

    Node *node = malloc(sizeof(Node));
    node->data = element;
    node->prev = cur;
    node->next = cur->next;
    cur->next = node;

    dll->length++;
}

int dll_get(DLL *dll, size_t index) {
    Node *cur = dll->head;
    for (size_t i = 0; i < index && i < dll->length - 1; i++) {
        cur = cur->next;
    }

    return cur->data;
}

void dll_reverse(DLL *dll);

void dll_replace(DLL *dll, size_t index, int element);

int dll_remove(DLL *dll, size_t index);

void dll_free(DLL *dll) {
    Node *cur = dll->head;
    while (cur != NULL) {
        Node *tmp = cur;

        cur = cur->next;
        tmp->prev = NULL;
        tmp->next = NULL;
        free(tmp);
    }

    dll->head = NULL;
    dll->tail = NULL;
    dll->length = 0;
}

void dll_print(DLL *dll) {
    Node *cur = dll->head;
    printf("[");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("] length = %ld\n", dll->length);
}
