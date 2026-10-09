typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char D_008735C0[];
extern char D_008739C0[];
extern "C" void func_0055E398(void *);
extern "C" void func_0055E3E0(void *, s32) throw();

extern "C" void func_0055EA38(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0055E398(D_008735C0);
    if (prio == 0xFFFF && init == 1) func_0055E398(D_008739C0);
    if (prio == 0xFFFF && init == 0) func_0055E3E0(D_008739C0, 0x2);
    if (prio == 0xFFFF && init == 0) func_0055E3E0(D_008735C0, 0x2);
}
