/* Stand-in for the C library header the compiler ships without; only what the matched third-party
   sources need (tools/libmatch.py inlines it, so src/ stays self-contained). */
#ifndef _ASSERT_H
#define _ASSERT_H
void abort(void);
#define assert(e) ((void)0)
#endif
