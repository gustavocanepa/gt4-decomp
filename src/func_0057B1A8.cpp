typedef int s32;
typedef unsigned int u32;

struct Pair { s32 key; s32 val; };
struct Map { Pair *items; u32 n; };

extern "C" s32 func_0057B1A8(Map *m, s32 key) {
    u32 i;
    for (i = 0; i < m->n; i++) {
        if (m->items[i].key == key) return m->items[i].val;
    }
    return 0;
}
