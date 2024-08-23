#ifndef _CLSM_H
#define _CLSM_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef CLSM_INCLUDES
#include <stdlib.h>
#include <stdio.h>
#endif // CLSM_INCLUDES

#ifdef NDEBUG
#define clsm_dbg_f(f, lv, cansi, msg) ((void)0)
#define clsm_dbg_info(msg) ((void)0)
#define clsm_dbg_warn(msg) ((void)0)
#define clsm_dbg_fatal(msg) ((void)0)
#else
#define clsm_dbg_f(f, lv, cansi, msg) \
do { \
	fprintf(f, "%s%s\033[0m", cansi, lv); \
	fprintf(f, "\t[%s:%d]: ", __FILE__, __LINE__); \
	fprintf(f, msg); \
	fprintf(f, "\n"); \
} while (0)
#define clsm_dbg_info(msg) clsm_dbg_f(stdout, "Info", "\033[0m", msg)
#define clsm_dbg_warn(msg) clsm_dbg_f(stderr, "Warn", "\033[0;33m", msg)
#define clsm_dbg_fatal(msg) clsm_dbg_f(stderr, "Fatal", "\033[0;31m", msg)
#endif // NDEBUG

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
