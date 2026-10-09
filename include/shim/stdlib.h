/* Stand-in for the C library header the compiler ships without; only what the matched third-party
   sources need (tools/libmatch.py inlines it, so src/ stays self-contained). */
#ifndef _STDLIB_H
#define _STDLIB_H
#include <stddef.h>
void *malloc(size_t);
void *realloc(void *, size_t);
void *calloc(size_t, size_t);
void free(void *);
int atoi(const char *);
long strtol(const char *, char **, int);
void exit(int);
#endif
