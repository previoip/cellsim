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

typedef struct {
	float pos[3];
	float vel[3];
	float hea[3];
} clsm_ent;


clsm_ent*
ce_new_ent(void) {
	clsm_ent* t = (clsm_ent*)clsm_malloc(sizeof(clsm_ent));
	return t;
}


float
ce_dist(clsm_ent* src, clsm_ent* dst);

#ifdef __cplusplus
extern }
#endif // __cplusplus

#endif // _CLSM_H
