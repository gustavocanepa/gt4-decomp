typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00623880[];
extern char D_006AA870[];
extern char D_00623878[];
extern "C" void func_0044CF10(void *, void *, void *);
extern "C" void func_0044CF30(void *, s32);

extern "C" void func_00450260(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0044CF10(D_00623880, D_006AA870, D_00623878);
    if (prio == 0xFFFF && init == 0) func_0044CF30(D_00623880, 0x2);
}
