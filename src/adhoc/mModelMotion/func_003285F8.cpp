/* Handle release: decrements a RefCounter's count with interrupts disabled (Sony's DIntr/EI pair);
   the last release calls func_00328498. */
struct RefCounter {
    int count;
};

extern "C" int func_005B72A8(void); /* DIntr: disables interrupts, returns whether they were enabled */
extern "C" void func_00328498(RefCounter *p);

extern "C" void func_003285F8(RefCounter *p)
{
    int enabled = func_005B72A8();
    int last = --p->count == 0;
    if (enabled)
        __asm__ volatile("ei");
    if (last)
        func_00328498(p);
}
