typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00845C40[];
extern char D_006A53D8[];
extern "C" void func_0057B198(void *, void *, s32);

extern "C" void func_00430210(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0057B198(D_00845C40, D_006A53D8, 0x17);
}
