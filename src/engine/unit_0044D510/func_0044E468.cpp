typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00623838[];
extern "C" void func_0044D818(void *);
extern "C" void func_0044D868(void *, s32) throw();

extern "C" void func_0044E468(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0044D818(D_00623838);
    if (prio == 0xFFFF && init == 0) func_0044D868(D_00623838, 0x2);
}
