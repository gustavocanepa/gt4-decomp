typedef int s32;
typedef short s16;

struct Stream {
    char pad0[0xC];
    s16 flags;
    char padE[0x58 - 0xE];
};

struct StreamBlock {
    struct StreamBlock *next;
    s32 count;
    struct Stream *streams;
};

struct Reent {
    char pad0[0x1D8];
    struct StreamBlock first;
};

/* Calls fn on every open stream of every block, ORing the results. */
s32 func_005A43A8(struct Reent *r, s32 (*fn)(struct Stream *)) {
    struct Stream *s;
    s32 n;
    s32 result = 0;
    struct StreamBlock *b;

    for (b = &r->first; b != 0; b = b->next)
        for (s = b->streams, n = b->count; --n >= 0; s++)
            if (s->flags != 0)
                result |= fn(s);
    return result;
}
