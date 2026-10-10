typedef int s32;

struct Elem { char b[0x30]; };
struct Obj { char pad[0x30]; Elem *items; };
extern "C" s32 func_003DE198(Obj *, s32);

extern "C" Elem *func_003DE4A8(Obj *o, s32 base, s32 x) {
    return &o->items[base + func_003DE198(o, x)];
}
