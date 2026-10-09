typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0064CCC0[];
extern "C" void func_005540E8(void *);
extern "C" void func_00554118(void *, s32) throw();

extern "C" void func_005541C0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_005540E8(D_0064CCC0);
    if (prio == 0xFFFF && init == 0) func_00554118(D_0064CCC0, 0x2);
}
