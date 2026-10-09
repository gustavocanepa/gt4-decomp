typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_006497B0[];
extern "C" void func_00503928(void *);
extern "C" void func_005039A8(void *, s32) throw();

extern "C" void func_00504598(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00503928(D_006497B0);
    if (prio == 0xFFFF && init == 0) func_005039A8(D_006497B0, 0x2);
}
