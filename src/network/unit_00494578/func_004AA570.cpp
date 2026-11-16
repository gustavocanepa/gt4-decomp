/* Takes a free scratchpad cache entry for key (releasing the current one first), pushes it on
   the head of the in-use list and returns its value, or -1 when no entry is free. */
#include "spr.h"
struct E { int a, b; unsigned char state, pad; signed char prev, next; int c, value; };
struct S {
    unsigned char pad[0xc30]; E entries[32]; char pad2[10]; signed char head, tail; char pad3[2];
    signed char index;
    int offset(int i) { return i * 20 + 0xc30; }
};
extern "C" int func_004AAA20(S *, int);
extern "C" void func_004AAD78(S *, int);
extern "C" int func_004AA570(int size, int key) {
    S *s = (S *)spr_base();
    /* Release the current entry. The block is a statement group of its own (a macro body in the
       original, by the look of it): its loop notes keep the index load below the parameter copies. */
    do {
        int i = s->index;
        if (i >= 0) {
            func_004AAD78(s, i);
            s->index = -1;
        }
    } while (0);
    int n = func_004AAA20(s, size);
    if (n >= 0) {
        int old = s->head;
        if (old >= 0) s->entries[old].prev = n;
        else s->tail = n;
        E *p = (E *)((char *)s + s->offset(n));
        p->prev = -1;
        p->next = old;
        s->head = n;
        p->state = 2;
    }
    s->entries[n + 1].b = key;
    if (n >= 0) return s->entries[n].value;
    return -1;
}
