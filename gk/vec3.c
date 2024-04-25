//
// Created by Justin Tunheim on 2/3/24.
//

#include <math.h>

#include "vec3.h"

vec3 vec3_new() { return (vec3) {.x = 0.0, .y = 0.0, .z = 0.0 }; }
vec3 vec3_invert_copy(vec3 v) { return (vec3) {.x = -v.x, .y = -v.y, .z = -v.z}; }

float vec3_magnitude(vec3 v)
{
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

float vec3_square_magnitude(vec3 v)
{
    return v.x*v.x+v.y*v.y+v.z*v.z;
}

vec3 vec3_mul_copy(vec3 v, float a)
{
    return (vec3) {.x = v.x * a, .y = v.y * a, .z = v.z * a };
}

vec3 vec3_add_copy(vec3 v, vec3 va)
{
    return (vec3) {
        .x = v.x + va.x,
        .y = v.y + va.y,
        .z = v.z + va.z,
    };
}

vec3 vec3_vec_product_copy(vec3 v, vec3 va)
{
    return (vec3) {
            .x = (v.y * va.z - v.z * va.y),
            .y = (v.z * va.x - v.x * va.z),
            .z = (v.x * va.y - v.y * va.x),
    };
}

vec3 vec3_add_scaled_copy(vec3 v, vec3 va, float scale)
{
    return (vec3) {
        .x = va.x * scale,
        .y = va.y * scale,
        .z = va.z * scale,
    };
}

float vec3_dot_product(vec3 v, vec3 va) { return v.x * va.x + v.y * va.y + v.z * va.z; }

void vec3_mul(vec3 *v, float a)
{
    v->x = v->x * a;
    v->y = v->y * a;
    v->z = v->z * a;
}

void vec3_add(vec3 *v, vec3 va)
{
    v->x = v->x + va.x;
    v->y = v->y + va.y;
    v->z = v->z + va.z;
}

void vec3_vec_product(vec3 *v, vec3 va)
{
    v->x = (v->y * va.z - v->z * va.y);
    v->y = (v->z * va.x - v->x * va.z);
    v->z = (v->x * va.y - v->y * va.x);
}

void vec3_add_scaled(vec3 *v, vec3 va, float scale)
{
    v->x = va.x * scale;
    v->y = va.y * scale;
    v->z = va.z * scale;
}

void vec3_invert(vec3 *v)
{
    v->x = -v->x;
    v->y = -v->y;
    v->z = -v->z;
}

void vec3_norm(vec3 *v)
{
    double l = vec3_magnitude(*v);
    if (l > 0) {
        vec3_mul(v, ((double)1/l));
    }
}