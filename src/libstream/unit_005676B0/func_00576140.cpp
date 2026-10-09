/* Leaves a nested interrupt-disabled section: the counterpart of func_00576100; the outermost
   leave re-enables interrupts if they were enabled when the section was entered. */
typedef int s32;

struct Obj {
    s32 depth;
    s32 enabled;
};

extern "C" void func_00576140(Obj *arg0)
{
    if (--arg0->depth == 0 && arg0->enabled)
        __asm__ volatile("ei");
}
