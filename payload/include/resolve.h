/* golden */
/* 1/2/2018 */

#ifndef _RESOLVE_H
#define _RESOLVE_H

#include "jkpatch.h"

// data
void *M_TEMP;

/** functions **/
// freebsd/common
int (*printf)(const char *fmt, ...);
void *(*k_malloc)(unsigned long size, void *type, int flags);
void (*k_free)(void *addr, void *type);

void resolve(uint64_t kernbase);

#endif
