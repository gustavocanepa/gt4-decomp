typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_006244D8[];
extern "C" void func_004723A0(void *);
extern "C" void func_004723D0(void *, s32) throw();

extern "C" void func_00472D50(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004723A0(D_006244D8);
    if (prio == 0xFFFF && init == 0) func_004723D0(D_006244D8, 0x2);
}
