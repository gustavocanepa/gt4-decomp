typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00622B60[];
extern "C" void RaceInput__structor_1(void *, s32);
extern "C" void RaceInput__structor_2(void *, s32) throw();

extern "C" void func_004270B0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) RaceInput__structor_1(D_00622B60, 0x0);
    if (prio == 0xFFFF && init == 0) RaceInput__structor_2(D_00622B60, 0x2);
}
