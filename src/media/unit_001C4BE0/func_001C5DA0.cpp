typedef int s32;

struct Block { char b[32]; };
struct Obj { s32 a; s32 b; struct Block blk; };

extern "C" void func_001C5DA0(struct Obj *o, s32 a, s32 b, const struct Block *blk) {
    o->a = a;
    o->b = b;
    o->blk = *blk;
}
