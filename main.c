#include <stdio.h>
#include <assert.h>
#include "linked_list/dl/double_linked_list.h"

int main()
{

    DLL *dll = dll_new();

    dll_print(dll);
    dll_insert_head(dll, 1);
    dll_insert_head(dll, 2);
    dll_insert_head(dll, 3);
    dll_insert_head(dll, 4);
    dll_insert_head(dll, 5);
    dll_insert_head(dll, 6);
    dll_insert_head(dll, 7);
    dll_insert_head(dll, 8);
    dll_print(dll);
    dll_insert_tail(dll, 10);
    dll_insert_tail(dll, 20);
    dll_insert_tail(dll, 30);
    dll_insert_tail(dll, 40);
    dll_insert_tail(dll, 50);
    dll_insert_tail(dll, 60);
    dll_insert_tail(dll, 70);
    dll_insert_tail(dll, 80);
    dll_print(dll);
    dll_insert(dll, 1, 100);
    dll_insert(dll, 0, 9);
    dll_insert(dll, 100, 90);
    dll_insert(dll, 3, 200);
    dll_insert(dll, 4, 300);
    dll_insert(dll, 5, 400);
    dll_insert(dll, 6, 500);
    dll_insert(dll, 7, 600);
    dll_insert(dll, 8, 700);
    dll_print(dll);

    assert(dll_get(dll, 0) == 9);
    assert(dll_get(dll, 1) == 8);
    assert(dll_get(dll, 2) == 100);
    assert(dll_get(dll, 3) == 200);
    assert(dll_get(dll, 8) == 700);
    assert(dll_get(dll, 11) == 5);
    assert(dll_get(dll, 15) == 1);
    assert(dll_get(dll, 16) == 10);
    assert(dll_get(dll, 20) == 50);
    assert(dll_get(dll, 24) == 90);
    assert(dll_get(dll, 25) == 90);
    assert(dll_get(dll, 1000) == 90);

    dll_free(dll);


    return 0;
}
