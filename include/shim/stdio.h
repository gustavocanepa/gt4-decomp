/* Stand-in for the C library header the compiler ships without; only what the matched third-party
   sources need (tools/libmatch.py inlines it, so src/ stays self-contained). */
#ifndef _STDIO_H
#define _STDIO_H
#include <stddef.h>
int printf(const char *, ...);
int sprintf(char *, const char *, ...);
#endif
