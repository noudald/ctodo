/* Debug macros copied from Zed's learn c the hard way. */

#ifndef __dbg_h_
#define __dbg_h_

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "Debug %s:%d: " M "\n", \
	__FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_error_number() (errno == 0 ? "None" : strerror(errno))

#define log_error(M, ...) fprintf(stderr, "Error: %s:%d:%s "  M "\n", \
	__FILE__, __LINE__, clean_error_number(), ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) { \
	log_error(M, ##__VA_ARGS__); errno = 0; goto error; }

#define check_memory(A) check((A), "Out of memory.")

#endif /* __dbg_h_ */
