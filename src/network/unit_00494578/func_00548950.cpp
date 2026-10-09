typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0086CB80[];
extern char D_0086CC80[];
extern "C" void func_00548368(void *);
extern "C" void func_00548458(void *);
extern "C" void func_00548498(void *, s32) throw();
extern "C" void func_005483C0(void *, s32) throw();

extern "C" void func_00548950(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00548368(D_0086CB80);
    if (prio == 0xFFFF && init == 1) func_00548458(D_0086CC80);
    if (prio == 0xFFFF && init == 0) func_00548498(D_0086CC80, 0x2);
    if (prio == 0xFFFF && init == 0) func_005483C0(D_0086CB80, 0x2);
}
