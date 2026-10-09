typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0086F800[];
extern "C" void func_00550AE0(void *);
extern "C" void func_00550B20(void *, s32) throw();

extern "C" void func_005510D8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00550AE0(D_0086F800);
    if (prio == 0xFFFF && init == 0) func_00550B20(D_0086F800, 0x2);
}
