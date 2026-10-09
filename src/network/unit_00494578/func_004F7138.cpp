typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00645570[];
extern "C" void func_004F01E8(void *);
extern "C" void func_004F0268(void *, s32) throw();

extern "C" void func_004F7138(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004F01E8(D_00645570);
    if (prio == 0xFFFF && init == 0) func_004F0268(D_00645570, 0x2);
}
