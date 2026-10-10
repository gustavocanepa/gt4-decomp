/* libio (GNU iostream library, gcc 2000-10-03 snapshot): __static_initialization_and_destruction_0 of streambuf.cc.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern "C" void func_00595338(void);

extern "C" void func_00594400(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 0) func_00595338();
}
