#include "spr.h"
typedef unsigned int u32;
struct E { u32 *tag; int b, c, d, e; };
struct Mid { char pad0[0xC30]; E e[1]; };
struct S {
    char pad0[0xEBC];
    signed char head;
    signed char tail;
    signed char index;
    char pad2[5];
    int xEC4;
};
extern "C" void func_004AAD78(S *, int);
extern "C" void func_004AAAF0(S *);
extern "C" void func_004A1FA8(S *, u32 mode);
extern "C" void func_004AA4A0(void) {
    S *s = (S *)spr_base();
    u32 *last;
    s->xEC4 = 0;
    do {
        int i = s->index;
        if (i >= 0) {
            func_004AAD78(s, i);
            s->index = -1;
        }
    } while (0);
    int i;
    last = 0;
    for (i = s->head; i >= 0; i = s->head) {
        last = ((Mid *)((char *)s + 0x14))->e[i].tag;
        func_004AAAF0(s);
    }
    if (last != 0) {
        do { *last = 0x91020000; } while (0);
        return func_004A1FA8(s, 0x10000);
    }
}
