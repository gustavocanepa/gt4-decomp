typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_006D6708[];
extern "C" void func_00100910(void *);
extern "C" void func_00100950(void *, s32) throw();

extern "C" void func_00100C78(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00100910(D_006D6708);
    if (prio == 0xFFFF && init == 0) func_00100950(D_006D6708, 0x2);
}
