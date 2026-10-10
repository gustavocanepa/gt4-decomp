typedef int s32;
struct Obj { s32 v; };
static inline void ctor(Obj *const self, s32 n) { self->v = n; }
extern char PDISTD__LOCALE[];
extern "C" void func_0048EE48(void *);
extern "C" void func_0048EE68(void *, s32) throw();

extern "C" void func_0048EEF8(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_0048EE48(PDISTD__LOCALE);
    if (prio == 0xFFFF && init == 0) func_0048EE68(PDISTD__LOCALE, 0x2);
}
