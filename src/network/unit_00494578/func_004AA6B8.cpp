/* Removes the entry holding value from the scratchpad's doubly linked list (indices, -1 ends),
   fixing its neighbours or the list's head and tail, clears its state and hands it back.
   The state store sits in a do-while(0): its loop notes keep it after the unlinking, as in retail. */
#include "spr.h"
struct E { signed char state, x1, next, prev; int b, value, d, key; };
struct Mid { char pad0[0xc28]; E e[32]; char pad[2]; signed char head, tail; char pad2[2]; signed char index; };
struct S { char pad0[0x10]; Mid m; };
extern "C" void func_004AAD78(S *, int);
extern "C" void func_004AA6B8(int value) {
    S *s = (S *)spr_base();
    if (value < 0) return;
    int i;
    for (i = s->m.head; i >= 0; i = s->m.e[i].prev) {
        if (s->m.e[i].value == value) {
            int next = s->m.e[i].next;
            int prev = s->m.e[i].prev;
            if (next >= 0) s->m.e[next].prev = prev;
            else s->m.head = prev;
            if (prev >= 0) s->m.e[prev].next = next;
            else s->m.tail = next;
            do { s->m.e[i].state = 0; } while (0);
            func_004AAD78(s, i);
            return;
        }
    }
}
