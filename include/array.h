//
// Created by Justin Tunheim on 4/15/24.
//

#ifndef CELL99_ARRAY_H
#define CELL99_ARRAY_H

#include <stdlib.h>

#define CELL99_ARRAY_DEFAULT_COUNT 16

typedef struct _c99_array {
    size_t size;
    size_t count;
    size_t capacity;
    void  *buff;
} array_t;

size_t           array_push(array_t *a, void *item);
array_t          array_init(size_t size, size_t capacity);
void             array_grow(array_t *a);
void             array_free(array_t *a);

#define array_new(type) array_init(sizeof(type), 0)

#endif //CELL99_ARRAY_H
