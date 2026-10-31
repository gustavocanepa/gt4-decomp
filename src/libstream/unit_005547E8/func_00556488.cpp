/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Returns a copy of the 44-byte record at +4 of o, read with interrupts
   disabled (func_005B72A8 = DIntr, then ei only if they were enabled). */
struct Rec { int x[11]; };
struct Obj { int f0; Rec rec; };
extern "C" int func_005B72A8(void);
extern "C" Rec func_00556488(Obj *o) {
    int enabled = func_005B72A8();
    Rec r = o->rec;
    if (enabled)
        __asm__ volatile("ei");
    return r;
}
