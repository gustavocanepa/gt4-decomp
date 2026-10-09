typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_006318D0[];
extern char D_00634B90[];
extern "C" void func_004B0250(void *);
extern "C" void func_00574D78(void *);
extern "C" void func_00574DA8(void *, s32) throw();
extern "C" void func_004B02E8(void *, s32) throw();

extern "C" void func_004B0890(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004B0250(D_006318D0);
    if (prio == 0xFFFF && init == 1) func_00574D78(D_00634B90);
    if (prio == 0xFFFF && init == 0) func_00574DA8(D_00634B90, 0x2);
    if (prio == 0xFFFF && init == 0) func_004B02E8(D_006318D0, 0x2);
}
