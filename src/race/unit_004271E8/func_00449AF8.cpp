/* compiler: ee-gcc2.96-nogcse */
/* Looks up a table row by its key and returns its string (data after the
   entries + off + 2), or 0. Without GCSE and with a goto loop (no loop
   optimisation) h->cnt is reloaded and e[i] stays indexed, as in the original. */
struct E { int off; int key; };
struct H { int f0; int cnt; int f8; int fc; E e[1]; };
struct T { H *h; };

static inline int key_at(H *h, E *e, int idx) {
    if (idx < 0) return -1;
    if (idx >= h->cnt) return -1;
    {
        E *r = &e[idx];
        return r->key;
    }
}

extern "C" char *func_00449AF8(T *t, int key) {
    H *h = t->h;
    int n = h->cnt;
    int i = 0;
    if (n > 0) {
        E *e = h->e;
        E *ke = e;
    loop:
        if (key == key_at(h, ke, i)) {
            E *r = &e[i];
            int o = r->off + 2;
            return (char *)(e + h->cnt) + o;
        }
        i++;
        if (i < n) goto loop;
    }
    return 0;
}
