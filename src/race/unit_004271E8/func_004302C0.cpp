typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00845C48[];
extern char D_006A54B0[];
extern "C" void func_0057B198(void *, void *, s32);

extern "C" void func_004302C0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0057B198(D_00845C48, D_006A54B0, 0x4);
}
