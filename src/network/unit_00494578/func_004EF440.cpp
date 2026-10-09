typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00645440[];
extern "C" void func_004EEA00(void *);
extern "C" void func_004EEA40(void *, s32) throw();

extern "C" void func_004EF440(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004EEA00(D_00645440);
    if (prio == 0xFFFF && init == 0) func_004EEA40(D_00645440, 0x2);
}
