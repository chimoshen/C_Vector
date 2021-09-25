#include"vector.h"

Vector vector_Create(const size_t type_size)
{
    Vector temp = (Vector)malloc(sizeof(vector));
    temp->data = malloc(type_size << 2);
    temp->actual_number = 4;
    temp->number = 0;
    temp->size = type_size;     
    return temp;
}

size_t vector_Length(Vector cv) 
{
    return cv->number;
}

void vector_Pushback(Vector cv, const void* add_element) 
{
    if (cv->number == cv->actual_number)
        vector_Recalloc(cv, cv->actual_number << 1);

    memcpy((char*)cv->data + cv->number++ * cv->size, add_element, cv->size);
}

void vector_Recalloc(Vector cv, const size_t new_number) 
{
    void* temp = realloc(cv->data, new_number * cv->size);
    if (temp)
        cv->data = temp;
    else
        return;
    cv->actual_number = new_number;
    if (cv->number > cv->actual_number)
        cv->number = cv->actual_number;
}

void vector_Popback(Vector cv) 
{
    if (cv->number == 0)
        return;
    if (cv->number == cv->actual_number >> 2 && cv->actual_number > 4)
    {
        vector_Recalloc(cv, cv->actual_number >> 2);
        cv->actual_number >>= 1;
    }
    cv->number--;
}

void vector_Free(Vector cv) 
{
    free(cv->data);
    free(cv);
    cv = NULL;
    return;
}

void vector_Clear(Vector cv) 
{
    cv->number = 0;
    vector_Recalloc(cv, 4);
}

void vector_Traversal(Vector cv, void(*fun)(void*)) 
{
    size_t i;
    for (i = 0; i < cv->number; ++i)
        fun((char*)cv->data + i * cv->size);
}

void vector_Insert(Vector cv, const size_t pos, const void* val) 
{
    if (pos > cv->number)
        return;
    else if (pos == cv->number)
        vector_Pushback(cv, val);
    else
    {
        if (cv->number == cv->actual_number)
            vector_Recalloc(cv, cv->actual_number>>1);
        memmove((char*)cv->data + (pos + 1) * cv->size, (char*)cv->data + pos * cv->size, (cv->number++ - pos) * cv->size);
        memcpy((char*)cv->data + pos * cv->size, val, cv->size);
    }
}

void vector_Erase(Vector cv, const size_t begin, const size_t end) {
    if (begin > cv->number || end > cv->number || begin > end)
        return;
    memmove((char*)cv->data + begin * cv->size, (char*)cv->data + end * cv->size, (cv->number - end) * cv->size);
    cv->number -= end - begin;
}

size_t vector_Size(Vector cv)
{
    return cv -> actual_number;
}