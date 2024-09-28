#ifndef _CLSM_H
#define _CLSM_H

#include "debug.h"
#define NENT 65535


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef CLSM_INCLUDES
#include <stdlib.h>
#include <stdio.h>
#endif /* CLSM_INCLUDES */

#ifndef clsm_malloc
#define clsm_malloc(size) malloc(size)
#endif /* clsm_malloc */

#ifndef clsm_free
#define clsm_free(p) free(p)
#endif /* clsm_free */


struct clsm_ent {
	struct clsm_ent *next;
	struct clsm_ent *prev;
	float pos[3];
	float vel[3];
	float hea[3];
	float power;
};


clsm_ent* clsm_newEnt(void);
float clsm_posDelta(clsm_ent* src, clsm_ent* dst);
float clsm_velDelta(clsm_ent* src, clsm_ent* dst);
float clsm_dist(clsm_ent* src, clsm_ent* dst);


#ifdef __cplusplus
extern }
#endif /* __cplusplus */

#endif /* _CLSM_H */
