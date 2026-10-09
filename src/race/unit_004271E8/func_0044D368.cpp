typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00623828[];
extern char D_006A7C98[];
extern char D_00623820[];
extern "C" void func_0044CF10(void *, void *, void *);
extern "C" void func_0044CF30(void *, s32) throw();

extern "C" void func_0044D368(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0044CF10(D_00623828, D_006A7C98, D_00623820);
    if (prio == 0xFFFF && init == 0) func_0044CF30(D_00623828, 0x2);
}
