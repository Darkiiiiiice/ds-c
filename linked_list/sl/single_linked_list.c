//
// Created by MarioMang on 2024/4/16.
//

#include "single_linked_list.h"


SLL *sll_new() {
    SLL *list = malloc(sizeof(SLL));
    list->head = NULL;
    list->length = 0;
    return list;
}

void sll_free(SLL *sll) {
    Node *cur = sll->head;
    while (cur != NULL) {
        Node *tmp = cur;
        cur = cur->next;

        sll->length--;
        free(tmp);
    }
    sll->head = NULL;
}

void sll_insert_head(SLL *sll, int element) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;

    if (sll->head == NULL) {
        sll->head = node;
        sll->length++;
        return;
    }

    node->next = sll->head;
    sll->head = node;
    sll->length++;
}


void sll_insert_tail(SLL *sll, int element) {
    Node *cur = sll->head;
    while (cur->next) {
        cur = cur->next;
    }
    Node *new = (Node *) malloc(sizeof(Node));
    new->data = element;
    new->next = NULL;

    cur->next = new;
    sll->length++;
}

void sll_insert(SLL *sll, size_t index, int element) {


    if (index >= sll->length) {
        return sll_insert_tail(sll, element);
    }

    Node *cur = sll->head;
    for (size_t i = 1; i < index; i++) {
        cur = cur->next;
    }

    Node *new = (Node *) malloc(sizeof(Node));
    new->data = element;
    new->next = cur->next;

    cur->next = new;
    sll->length++;

}

int sll_get(SLL *sll, size_t index) {
    Node *cur = sll->head;
    while (cur->next && index > 0) {
        cur = cur->next;
        index--;
    }
    return cur->data;
}


void sll_reverse(SLL *sll) {
    Node *cur = sll->head;
    Node *head = NULL;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        tmp->next = head;
        head = tmp;
    }
    sll->head = head;
}

void sll_replace(SLL *sll, size_t index, int element) {
    Node *cur = sll->head;
    while (cur->next && index > 0) {
        cur = cur->next;
        index--;
    }
    cur->data = element;
}

int sll_remove(SLL *sll, size_t index) {
    Node *cur = sll->head;
    if (index == 0) {
        int data = cur->data;
        sll->head = cur->next;
        sll->length--;
        free(cur);
        return data;
    }


    Node *last = cur;
    while (cur->next && index > 0) {
        last = cur;
        cur = cur->next;
        index--;
    }
    int data = cur->data;
    Node *tmp = cur;
    last->next = cur->next;
    free(tmp);
    sll->length--;
    return data;
}

void sll_print(SLL *sll) {
    Node *cur = sll->head;
    printf("[");
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;

        printf("%d -> ", tmp->data);
    }
    printf("NULL]");

    printf("(length: %zu)\n", sll->length);
}