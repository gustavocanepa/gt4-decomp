typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0064CD00[];
extern "C" void func_00555088(void *);
extern "C" void func_00555100(void *, s32) throw();

extern "C" void func_005562E8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00555088(D_0064CD00);
    if (prio == 0xFFFF && init == 0) func_00555100(D_0064CD00, 0x2);
}
