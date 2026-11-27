/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
struct Item {
    union { u32 flags; u16 id; };
    char pad4[10];
    s8 skip;
    char padF[2];
    u8 used;
    char pad12[10];
};
struct Block {
    Item items[42];
    u8 count;
    char pad499[7];
    Item *more[42];
    u16 extraKind;
    Item *extra;
    u16 extraCount;
};
struct Context {
    char pad0[0x2C];
    int *state;
    Block *block;
    Item *current;
};
extern "C" u16 *func_004C8C20(Context *, int);
#define ADD(x) { id = (x); if (n == 0 || p[-1] != id) { *p++ = id; n++; } }
extern "C" int func_004C0A28(Context *ctx, u16 **out) {
    int n = 0;
    int i;
    int j;
    u16 id;
    Item *it;
    u16 *buf;
    u16 *p;
    if (*ctx->state == 101) {
        if (ctx->block->extraKind != 0x7FFF) {
            Item *e = ctx->block->extra;
            if (e) {
                int c = ctx->block->extraCount;
                it = e;
                for (j = 0; j < c; j++) {
                    if (it->flags & 0xC00000) n++;
                    it++;
                }
            }
        }
        for (i = 0; i < ctx->block->count; i++) {
            it = &ctx->block->items[i];
            if (it->flags & 0xC00000) n++;
            if (ctx->block->more[i]) {
                it = ctx->block->more[i];
                if (it->flags & 0xC00000) n++;
            }
        }
    }
    if (ctx->current->used && (ctx->current->flags & 0xC00000) && ctx->current->skip == 0) n++;
    if (n == 0) {
        *out = 0;
        return 0;
    }
    buf = func_004C8C20(ctx, n * 2);
    *out = buf;
    if (buf == 0) {
        *out = 0;
        return -1;
    }
    p = buf;
    n = 0;
    if (*ctx->state == 101) {
        if (ctx->block->extraKind != 0x7FFF) {
            Item *e = ctx->block->extra;
            if (e) {
                int c = ctx->block->extraCount;
                it = e;
                for (j = 0; j < c; j++) {
                    if (it->flags & 0xC00000) ADD(it->id);
                    it++;
                }
            }
        }
        for (i = 0; i < ctx->block->count; i++) {
            it = &ctx->block->items[i];
            if (it->flags & 0xC00000) ADD(it->id);
            if (ctx->block->more[i]) {
                it = ctx->block->more[i];
                if (it->flags & 0xC00000) ADD(it->id);
            }
        }
    }
    if (ctx->current->used && (ctx->current->flags & 0xC00000) && ctx->current->skip == 0) ADD(ctx->current->id);
    return n;
}
