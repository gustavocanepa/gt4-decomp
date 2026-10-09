typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_006235A8[];
extern "C" void func_00443308(void *);
extern "C" void func_00443378(void *, s32) throw();

extern "C" void func_004440F8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00443308(D_006235A8);
    if (prio == 0xFFFF && init == 0) func_00443378(D_006235A8, 0x2);
}
