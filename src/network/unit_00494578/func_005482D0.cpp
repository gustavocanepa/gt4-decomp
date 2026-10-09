typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0086CA40[];
extern "C" void func_00547CE0(void *);
extern "C" void func_00547D20(void *, s32) throw();

extern "C" void func_005482D0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00547CE0(D_0086CA40);
    if (prio == 0xFFFF && init == 0) func_00547D20(D_0086CA40, 0x2);
}
