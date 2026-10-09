/* Stand-in for the C library header the compiler ships without; only what the matched third-party
   sources need (tools/libmatch.py inlines it, so src/ stays self-contained). */
#ifndef _NEW_H
#define _NEW_H
#include <stddef.h>
/* placement new as gcc 2.96 declares it: an inline function, hence the null test before a
   construct() in matched STL code (knowledge/gt4.md) */
inline void *operator new(size_t, void *__p) throw() { return __p; }
inline void *operator new[](size_t, void *__p) throw() { return __p; }
#endif
