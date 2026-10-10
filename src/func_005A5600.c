/* newlib 1.9.0 libc/stdlib/rand.c: rand(), compiled with strict aliasing (unlike most of newlib):
   the _impure_ptr load is kept across the store. The file has no notice of its own
   (COPYING.NEWLIB section 9, THIRD_PARTY.md). */
struct _reent {
    char pad[0xA8];
    unsigned long long _rand_next; /* _new._reent._rand_next */
};

extern struct _reent *D_00658288; /* _impure_ptr */
#define _REENT D_00658288
#define RAND_MAX 0x7fffffff

int func_005A5600(void)
{
    /* This multiplier was obtained from Knuth, D.E., "The Art of
       Computer Programming," Vol 2, Seminumerical Algorithms, Third
       Edition, Addison-Wesley, 1998, p. 106 (line 26) & p. 108 */
    _REENT->_rand_next =
        _REENT->_rand_next * __extension__ 6364136223846793005LL + 1;
    return (int)((_REENT->_rand_next >> 32) & RAND_MAX);
}
