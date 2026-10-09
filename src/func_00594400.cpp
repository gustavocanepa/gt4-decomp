typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern "C" void func_00595338(void);

extern "C" void func_00594400(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 0) func_00595338();
}
