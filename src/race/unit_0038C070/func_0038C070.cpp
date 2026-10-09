typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_00621340[];
extern "C" void RaceBGMBase__structor_0(void *);
extern "C" void RaceBGMBase__structor_1(void *, s32) throw();

extern "C" void func_0038C070(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) RaceBGMBase__structor_0(D_00621340);
    if (prio == 0xFFFF && init == 0) RaceBGMBase__structor_1(D_00621340, 0x2);
}
