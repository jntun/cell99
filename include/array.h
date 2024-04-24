//
// Created by Justin Tunheim on 4/15/24.
//

#ifndef CELL99_ARRAY_H
#define CELL99_ARRAY_H

#include <stdlib.h>

#define CELL99_ARRAY_DEFAULT_COUNT 16

typedef size_t asize_t;

typedef struct _c99_array {
    asize_t size;
    asize_t count;
    asize_t capacity;
    void  *buff;
} array_t;

size_t           array_push(array_t *a, void *item);
array_t          array_init(asize_t size, asize_t capacity);
void             array_grow(array_t *a);
void             array_free(array_t *a);

#define array_new(type) array_init(sizeof(type), 0)
#define array_t_decl(type) array_t

#endif //CELL99_ARRAY_H
