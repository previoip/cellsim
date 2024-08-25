#ifndef _CLSM_H
#define _CLSM_H

#include "debug.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef CLSM_INCLUDES
#include <stdlib.h>
#include <stdio.h>
#endif // CLSM_INCLUDES

#ifndef clsm_malloc
#define clsm_malloc(size) malloc(size)
#endif // clsm_malloc

#ifndef clsm_free
#define clsm_free(p) free(p)
#endif // clsm_free

#define vec2_init(T) (T*)calloc(2, sizeof(T))
#define vec3_init(T) (T*)calloc(3, sizeof(T))

typedef struct {
	int id;
	double* v3pos;
	double* v3vel;
	double* v3acc;
	double* v2hea;
} clsm_ent;

void clsm_ent_init(clsm_ent* ent) {
	ent->v3pos = vec3_init(double);
	ent->v3vel = vec3_init(double);
	ent->v3acc = vec3_init(double);
	ent->v2hea = vec2_init(double);
}

#ifdef __cplusplus
extern }
#endif // __cplusplus

#endif // _CLSM_H
