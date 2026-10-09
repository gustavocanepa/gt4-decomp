typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0086F8C0[];
extern "C" void func_00551170(void *);
extern "C" void func_005511B0(void *, s32) throw();

extern "C" void func_005514D0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00551170(D_0086F8C0);
    if (prio == 0xFFFF && init == 0) func_005511B0(D_0086F8C0, 0x2);
}
