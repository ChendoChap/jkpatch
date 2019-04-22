/* golden */
/* 1/2/2018 */

#include "resolve.h"

void resolve(uint64_t kernbase) {
	M_TEMP = (void *)(kernbase + __M_TEMP);

#define r(name, offset) name = (void *)(kernbase + offset)
	r(printf, __printf);
	r(k_malloc, __malloc);
	r(k_free, __free);
}
