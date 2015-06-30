#include <omp.h>
#include <stdio.h>

const char* FindAnyNeedle(const char* haystack, size_t size, char needle) {
	const char* result = NULL;
	bool done = false;
	size_t beginpos = 0, n_per_loop = 4096 * omp_get_max_threads();
	while(beginpos < size && !done) {
		size_t endpos = std::min(size, beginpos + n_per_loop);
		#pragma omp parallel for reduction(|:done)
		for(size_t p = beginpos; p < endpos; ++p)
			if(haystack[p] == needle) {
				/* Found it. */
				done = true;
				result = haystack+p;
			}
		beginpos = endpos;
	}
	return result;
}
