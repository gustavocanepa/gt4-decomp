typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00620320[];
extern "C" void func_00350660(void *) throw();

extern "C" void func_003509E8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00350660(D_00620320);
}
