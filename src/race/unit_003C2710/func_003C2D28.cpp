typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00621B50[];
extern "C" void func_003C2B20(void *) throw();

extern "C" void func_003C2D28(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_003C2B20(D_00621B50);
}
