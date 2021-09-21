#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct {
    void*   data;
    size_t  size;
    size_t  number;
    size_t  actual_number;
}vector, * Vector;

Vector  vector_Create(size_t type_size);
size_t  vector_length(Vector cv);
void    vector_Pushback(Vector cv, void* add_element);
void    vector_Recalloc(Vector cv, size_t new_number);
void    vector_Popback(Vector cv);
void    vector_Free(Vector cv);
void    vector_Clear(Vector cv);
void    vector_Traversal(Vector cv, void(*fun)(void*));
void    vector_Erase(Vector cv, size_t begin, size_t end);
void    vector_insert(Vector cv, size_t pos, void* val);