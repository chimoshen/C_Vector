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

Vector  vector_Create(const size_t type_size);
size_t  vector_Length(Vector cv);
size_t  vector_Size(Vector cv);
void    vector_Pushback(Vector cv, const void* add_element);
void    vector_Recalloc(Vector cv, const size_t new_number);
void    vector_Popback(Vector cv);
void    vector_Free(Vector cv);
void    vector_Clear(Vector cv);
void    vector_Traversal(Vector cv, void(*fun)(void*));
void    vector_Erase(Vector cv, const size_t begin, const size_t end);
void    vector_Insert(Vector cv,  const size_t pos, const void* val);