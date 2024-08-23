#ifndef _CLSM_H_
#define _CLSM_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef CLSM_INCLUDES
#include <stdio.h>
#endif // CLSM_INCLUDES

#ifdef NDEBUG
#define CLSM_LOG_INFO(msg)	((void)0)
#define CLSM_LOG_WARN(msg)	((void)0)
#define CLSM_LOG_FATAL(msg)	((void)0)
#else

#define CLSM_LOG_INFO(msg)									\
do {														\
	fprintf(stderr, "INFO [%s:%d]: ", __FILE__, __LINE__);	\
	fprintf(stderr, msg);									\
	fprintf(stderr, "\n");									\
} while (0)

#define CLSM_LOG_WARN(msg)									\
do {														\
	fprintf(stderr, "WARN [%s:%d]: ", __FILE__, __LINE__);	\
	fprintf(stderr, msg);									\
	fprintf(stderr, "\n");									\
} while (0)

#define CLSM_LOG_FATAL(msg)									\
do {														\
	fprintf(stderr, "FATAL [%s:%d]: ", __FILE__, __LINE__);	\
	fprintf(stderr, msg);									\
	fprintf(stderr, "\n");									\
} while (0)

#endif // NDEBUG

#ifndef CLSM_MALLOC
#define clsm_malloc(size) malloc(size)
#define clsm_free(size)	free(size)
#endif // CLSM_MALLOC

#ifdef __cplusplus
extern }
#endif // __cplusplus

#endif // _CLSM_H_
