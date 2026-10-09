typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_0086C8D8[];
extern char D_0086C8E0[];
extern "C" void func_00576090(void *);
extern "C" void func_005474C8(void *);
extern "C" void func_005474F8(void *, s32);
extern "C" void func_005760A8(void *, s32);

extern "C" void func_00547C10(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_00576090(D_0086C8D8);
    if (prio == 0xFFFF && init == 1) func_005474C8(D_0086C8E0);
    if (prio == 0xFFFF && init == 0) func_005474F8(D_0086C8E0, 0x2);
    if (prio == 0xFFFF && init == 0) func_005760A8(D_0086C8D8, 0x2);
}
