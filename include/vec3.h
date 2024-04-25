//
// Created by Justin Tunheim on 2/3/24.
//

#ifndef CELL99_VEC3_H
#define CELL99_VEC3_H

typedef struct vec3 {
    float x, y, z;
} vec3;

vec3  vec3_new();
void  vec3_invert          (vec3 *v);
void  vec3_norm            (vec3 *v);
void  vec3_mul             (vec3 *v, float a);
void  ec3_add              (vec3 *v, vec3 va);
void  vec3_vec_product     (vec3 *v, vec3 va);
void  vec3_add_scaled      (vec3 *v, vec3 va, float scale);
vec3  vec3_invert_copy     (vec3 v);
float vec3_magnitude       (vec3 v);
float vec3_square_magnitude(vec3 v);
vec3  vec3_mul_copy        (vec3 v, float a);
vec3  vec3_add_copy        (vec3 v, vec3 va);
vec3  vec3_vec_product_copy(vec3 v, vec3 va);
vec3  vec3_add_scaled_copy (vec3 v, vec3 va, float scale);
float vec3_dot_product     (vec3 v, vec3 va);

#endif //CELL99_VEC3_H
