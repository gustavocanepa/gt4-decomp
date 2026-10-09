typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0064FBF8[];
extern "C" void func_00559680(void *) throw();

extern "C" void func_005598A8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00559680(D_0064FBF8);
}
