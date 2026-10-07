typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, s32); };
struct Obj { struct VEntry *vtbl; s32 elems[0x300]; };

extern "C" s32 func_00431360(void *arg0, s32 arg1);

extern "C" void func_00431458(struct Obj *o, s32 arg1)
{
    s32 v = arg1;
    int i;
    for (i = 0; i < 0x300; i++) v = func_00431360(&o->elems[i], v);
    struct VEntry *e = o->vtbl + 4;
    e->fn((char *)o + e->delta, arg1);
}
