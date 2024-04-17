//
// Created by Justin Tunheim on 4/15/24.
//

#include <stdio.h>
#include <string.h>

#include "array.h"

void array_push(array_t *a, void *item)
{
    if (a->count == a->capacity) {
array_grow(a);
    }
    void *insert = a->buff + (a->count * a->size);
    memcpy(insert, item, a->size);
    a->count++;
}

array_t array_init(size_t size, size_t capacity)
{
    array_t a = {
            .size = size,
            .count = 0,
            .capacity = capacity ? capacity : CELL99_ARRAY_DEFAULT_COUNT,
            .buff = NULL
    };
    a.buff = malloc(a.size * a.capacity);
    return a;
}

void array_grow(array_t *a)
{
    size_t new_length = a->capacity * 2;
    char *new_buf = malloc(a->size * new_length);
    memcpy(new_buf, a->buff, (a->size * a->capacity));
    a->capacity = new_length;
    free(a->buff);
    a->buff = new_buf;
}

void array_free(array_t *a)
{
    a->size = 0;
    a->count = 0;
    a->capacity = 0;
    free(a->buff);
}
