//
// Created by Justin Tunheim on 4/24/24.
//

#ifndef CELL99_WAVEFRONT_H
#define CELL99_WAVEFRONT_H

#include "falia.h"
#include "vec3.h"

// WAVEFRONT OBJ FILE (see: https://en.wikipedia.org/wiki/Wavefront_.obj_file)
// typedef symbols are re-used from there

// If there are more than 4 entries for a face's vertex indices,
// those will have to be allocated elsewhere than the face's memory.
#define WAVEFRONT_FACE_STACK 4

#define WAVEFRONT_OPTIONAL_ARRAY_INIT 3

#define WAVEFRONT_INDEX_VALUES() \
            WAVEFRONT_INDEX_VALUE(0), \
            WAVEFRONT_INDEX_VALUE(1), \
            WAVEFRONT_INDEX_VALUE(2), \
            WAVEFRONT_INDEX_VALUE(3)  \

#define WAVEFRONT_INDEX_VALUE(f, i)         \
            f.indices[i].index[0].value, \
            f.indices[i].index[1].value, \
            f.indices[i].index[2].value  \

typedef vec3 wavefront_vertex;
typedef vec3 wavefront_vnormal;

typedef struct wavefront_vtexture {
    double x, y;
};

typedef enum {
    WAVEFRONT_INDEX_EMPTY,
    WAVEFRONT_INDEX_VERTEX,
} wavefront_index_type;

typedef struct {
    wavefront_index_type type;
    ssize_t value;
} wavefront_index;

typedef struct wavefront_vindex {
    wavefront_index index[3]; // A face vertex index always has 3 index values
};

/*!
 * @struct wavefront_face
 * @field optional_indices is an array of indices into one large array of all the optional vindex structs
 */
typedef struct wavefront_face {
    struct wavefront_vindex indices[WAVEFRONT_FACE_STACK];
    array_t_decl(asize_t)   optional_indices;
};

/*!
 * @struct An .obj (and possibly .mtl) file representation
 */
struct wavefront_obj {
    array_t_decl(wavefront_vertex)   v;
    array_t_decl(wavefront_vtexture) vt;
    array_t_decl(wavefront_vnormal)  vn;
    array_t_decl(wavefront_face)     f;
    array_t_decl(wavefront_vindex)   optional_pool;
};

struct wavefront_obj wavefront_obj_open(char *path);

#endif //CELL99_WAVEFRONT_H
