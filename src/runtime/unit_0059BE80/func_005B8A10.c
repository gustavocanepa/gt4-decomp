/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned int u32;
typedef long long s64;

struct Slot {
    s32 f0;
    s32 f4;
    u32 gen;
    u32 flags;
    s64 a;
    s64 b;
    char pad[0x20];
};

s64 func_005B8A10(s32 id) {
    /* the slot table sits at address 0 (no base register in the original) */
    struct Slot *s = &((struct Slot *)0)[(u32)id >> 10];
    if (id < 0 || (id & 0x3FF) != s->gen)
        return -1;
    if (s->flags & 1)
        return s->a - s->b;
    return 0;
}
