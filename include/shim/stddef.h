/* Stand-in for the C library header the compiler ships without; only what the matched third-party
   sources need (tools/libmatch.py inlines it, so src/ stays self-contained). */
#ifndef _STDDEF_H
#define _STDDEF_H
#ifndef SHIM_SIZE_T
#define SHIM_SIZE_T unsigned int
#endif
typedef SHIM_SIZE_T size_t;
#ifndef SHIM_PTRDIFF_T
#define SHIM_PTRDIFF_T int
#endif
typedef SHIM_PTRDIFF_T ptrdiff_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif
