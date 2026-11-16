typedef signed char s8;
typedef unsigned char u8;
struct Entry { u8 used; u8 pad1; s8 next; s8 prev; int pad4[2]; int *tag; int key; };
struct Pool { char pad0[0xC30]; struct Entry entries[1]; };
struct Cache { char pad0[8]; struct Pool pool; };
#define TAIL(s) (*((s8 *)(s) + 0xEBC))
#define HEAD(s) (*((s8 *)(s) + 0xEBD))
/* Find the cache entry holding `key`, unlink it from the in-use list and free it.
   Returns its index, or -1. */
int func_004AAF38(struct Cache *s, int key) {
    s8 i;
    for (i = HEAD(s); i >= 0; i = s->pool.entries[i].next) {
        if (s->pool.entries[i].key == key) {
            s8 next, prev;
            s->pool.entries[i].tag = 0;
            /* statement block (list-remove macro in the original): keeps its stores in place */
            do {
            next = s->pool.entries[i].next;
            prev = s->pool.entries[i].prev;
            if (next >= 0) s->pool.entries[next].prev = prev;
            else TAIL(s) = prev;
            if (prev >= 0) s->pool.entries[prev].next = next;
            else HEAD(s) = next;
            s->pool.entries[i].used = 0;
            } while (0);
            return i;
        }
    }
    return -1;
}
