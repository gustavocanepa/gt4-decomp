typedef int s32;
typedef short s16;

struct Item { s32 w[9]; };
struct Table { char pad[0x30]; Item *items; };
struct Ctx { char pad[0x6E20]; Table *t; };
extern "C" Ctx *func_00474568(Item *);

extern "C" Ctx *func_00479180(s16 *id, Ctx *ctx) {
    s32 i = *id;
    if (i >= 0) {
        ctx = func_00474568(&ctx->t->items[i]);
    }
    return ctx;
}
