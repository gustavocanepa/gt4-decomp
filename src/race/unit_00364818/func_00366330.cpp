typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00620B00[];
extern "C" void func_003660D8(void *) throw();

extern "C" void func_00366330(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_003660D8(D_00620B00);
}
