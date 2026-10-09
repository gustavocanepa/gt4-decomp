typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00650500[];
extern "C" void func_0055A3D8(void *) throw();

extern "C" void func_0055A6D8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0055A3D8(D_00650500);
}
