typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_006184C0[];
extern "C" void func_00105FD8(void *) throw();

extern "C" void func_00106000(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00105FD8(D_006184C0);
}
