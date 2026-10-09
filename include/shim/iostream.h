/* Stand-in for the C library header the compiler ships without; only what the matched third-party
   sources need (tools/libmatch.py inlines it, so src/ stays self-contained). */
#ifndef _IOSTREAM_H
#define _IOSTREAM_H
/* enough for stl_iterator.h to parse istream_iterator / ostream_iterator (never instantiated) */
class istream;
class ostream;
extern istream cin;
extern ostream cout;
#endif
