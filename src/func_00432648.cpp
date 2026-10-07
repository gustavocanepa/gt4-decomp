typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *, s32); };
struct Elem { char data[0x1F8]; };
struct Obj { struct VEntry *vtbl; struct Elem elems[125]; };
extern "C" s32 func_00432550(void *arg0, s32 arg1);
extern "C" void func_00432648(struct Obj *o, s32 arg1)
{
    s32 v = arg1; int i;
    for (i = 0; i < 125; i++) v = func_00432550(&o->elems[i], v);
    struct VEntry *e = o->vtbl + 4;
    e->fn((char *)o + e->delta, arg1);
}
