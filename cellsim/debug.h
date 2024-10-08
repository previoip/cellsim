#ifndef _CLSM_DEBUG_H
#define _CLSM_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

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

#ifdef __cplusplus
extern }
#endif // __cplusplus

#endif // _CLSM_DEBUG_H