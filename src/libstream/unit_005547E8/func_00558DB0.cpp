/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Channel level: scales x by its table entry (mul * x / div, at least 1); with 'clamp' the new
   level stays within half and twice the current one. '!(v <= hi)' is what leaves retail's
   'xori v0, v0, 0' (the <= flag inverted twice). */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
struct Tab { s16 div; s16 pad; s32 x4; u32 mul; s32 xC; };
struct Ch { s32 x0; s32 idx; s32 x8; s32 xC; s32 level; s32 x14; };
struct Obj { char pad[0x30]; Tab *tab; };
extern "C" void func_00558DB0(Obj *o, s32 ch, u32 x, s32 clamp) {
    Ch *c = (Ch *)((char *)o + ch * 24);
    Tab *t = &o->tab[c->idx];
    s32 v = (t->mul * x) / t->div;
    if (!(v > 0)) v = 1;
    if (clamp) {
        s32 cur = c->level;
        s32 hi = cur << 1;
        s32 lo = cur >> 1;
        if (!(v <= hi)) v = hi;
        else if (v < lo) v = lo;

    }
    c->level = v;
}
