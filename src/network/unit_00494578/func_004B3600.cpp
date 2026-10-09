typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00851180[];
extern "C" void func_004B22A8(void *);
extern "C" void func_004B2240(void *, s32) throw();

extern "C" void func_004B3600(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004B22A8(D_00851180);
    if (prio == 0xFFFF && init == 0) func_004B2240(D_00851180, 0x2);
}
