typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00846918[];
extern char D_00846948[];
extern char D_00846950[];
extern "C" void func_00574D78(void *);
extern "C" void func_00576090(void *);
extern "C" void func_005792D8(void *);
extern "C" void func_005760A8(void *, s32);
extern "C" void func_00574DA8(void *, s32);

extern "C" void func_00462370(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00574D78(D_00846918);
    if (prio == 0xFFFF && init == 1) func_00576090(D_00846948);
    if (prio == 0xFFFF && init == 1) func_005792D8(D_00846950);
    if (prio == 0xFFFF && init == 0) func_005760A8(D_00846948, 0x2);
    if (prio == 0xFFFF && init == 0) func_00574DA8(D_00846918, 0x2);
}
