typedef short s16;
typedef int s32;

struct Link { s16 next; s16 pad; s32 m4; };
struct Key { s32 key; s32 pad; };
/* The key is read through a second view based at +4 (the original hoists t + 4 out of the loop
   as its own base register), the link through the view based at +0. */
struct Table { union { Link links[1]; struct { s32 pad; Key keys[1]; } k; } u; };

extern "C" Link *func_003B7278(Table *t, s32 key) {
    s32 i = ((s32 *)t)[2];
    while (i >= 0) {
        if (key == t->u.k.keys[i].key) return &t->u.links[i];
        i = t->u.links[i].next;
    }
    return 0;
}
