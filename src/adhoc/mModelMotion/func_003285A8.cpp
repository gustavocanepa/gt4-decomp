/* Handle retain: increments a RefCounter's count with interrupts disabled (Sony's DIntr/EI pair);
   the first reference calls func_00328660. */
struct RefCounter {
    int count;
};

extern "C" int func_005B72A8(void); /* DIntr: disables interrupts, returns whether they were enabled */
extern "C" void func_00328660(RefCounter *p);

extern "C" void func_003285A8(RefCounter *p)
{
    int enabled = func_005B72A8();
    int first = p->count == 0;
    p->count = p->count + 1;
    if (enabled)
        __asm__ volatile("ei");
    if (first)
        func_00328660(p);
}
