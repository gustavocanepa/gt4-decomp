/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Binary search of a table row by its u32 key; returns the row index or -1.
   key_at takes the row address through a named pointer (r = &e[idx]) so the
   loop-invariant base h->e stays in its own register, as in the original. */
struct E { unsigned int a; int b; };
struct H { char p0[8]; int cnt; int size; E e[1]; };
struct T { H *h; };
static inline unsigned int key_at(T *t, int idx) {
    if (idx < 0) return (unsigned int)-1;
    if (idx >= t->h->cnt) return (unsigned int)-1;
    {
        E *e = t->h->e;
        E *r = &e[idx];
        return r->a;
    }
}
extern "C" int SPEC_DATABASE__DatabaseTable__searchNumber(T *t, unsigned int key) {
    int lo = -1;
    int hi = t->h->cnt;
    if (hi <= 0) return -1;
    do {
        int mid = (lo + hi) >> 1;
        unsigned int k = key_at(t, mid);
        if (k == key) return mid;
        if (k < key) lo = mid;
        else hi = mid;
    } while (lo + 1 != hi);
    return -1;
}
