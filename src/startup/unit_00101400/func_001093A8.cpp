typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0081ED48[];
extern char D_00618700[];
extern "C" void func_00108F78(void *, void *);
extern "C" void func_00108FE0(void *, s32);

extern "C" void func_001093A8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00108F78(D_0081ED48, D_00618700);
    if (prio == 0xFFFF && init == 0) func_00108FE0(D_0081ED48, 0x2);
}
