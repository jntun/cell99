//
// Created by Justin Tunheim on 4/16/24.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "wavefront.h"

#define WAVEFRONT_OBJ_EXT ".obj"
#define WAVEFRONT_MTL_EXT ".mtl"

static struct wavefront_obj default_obj()
{
    return (struct wavefront_obj) {
            .v  = array_new(wavefront_vertex),
            .vt = array_new(struct wavefront_vtexture),
            .vn = array_new(wavefront_vnormal),
            .f  = array_new(struct wavefront_face),
            .optional_pool = array_new(struct wavefront_vindex),
    };
}

struct wavefront_obj wavefront_obj_open(char *path)
{
    struct wavefront_obj obj = default_obj();
    char *full_path;
    asprintf(&full_path, "%s%s%s", FALIA_MODEL_PATH, path, WAVEFRONT_OBJ_EXT);

    FILE *file = fopen(full_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open path: %s\n", full_path);
        goto EXIT;
    }

    while (1) {
        char lineHeader[128];

        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break;

        if (strcmp(lineHeader, "v") == 0) {
            wavefront_vertex vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            array_push(&obj.v, &vertex);
        } else if (strcmp(lineHeader, "vt") == 0) {
            struct wavefront_vtexture vt;
            fscanf(file, "%f %f\n", &vt.x, &vt.y);
            array_push(&obj.vt, &vt);
        } else if (strcmp(lineHeader, "vn") == 0) {
            wavefront_vnormal vn;
            fscanf(file, "%f %f %f\n", &vn.x, &vn.y, &vn.z);
            array_push(&obj.vn, &vn);
        } else if (strcmp(lineHeader, "f") == 0) {
            struct wavefront_face f = {
                    .optional_indices = array_init(sizeof(asize_t), 3),
            };
            size_t fcount = 0;
            char *const face_fmt = "%zd/%zd/%zd";

            while (1) {
                if (fcount < WAVEFRONT_FACE_STACK) {
                    fscanf(file, face_fmt, WAVEFRONT_INDEX_VALUE(&f, fcount));
                } else {
                    struct wavefront_vindex vin;

                    fscanf(file, face_fmt, &vin.index[0].value, &vin.index[1].value, &vin.index[2].value);
                    vin.index[0].type = WAVEFRONT_INDEX_VERTEX;
                    vin.index[1].type = WAVEFRONT_INDEX_VERTEX;
                    vin.index[2].type = WAVEFRONT_INDEX_VERTEX;
                    asize_t opt_index = array_push(&obj.optional_pool, &vin);
                    array_push(&f.optional_indices, &opt_index);
                }
                int c = fgetc(file);
                if (c == ' ')  fcount++;
                else break;
            }
            array_push(&obj.f, &f);
        }
    }

EXIT:
    return obj;
}
