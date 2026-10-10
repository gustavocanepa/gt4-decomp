typedef int s32;

extern volatile s32 D_0064C3F0;
extern "C" s32 func_005B72A8(void);

/* Swap the global with interrupts disabled (func_005B72A8 is DI returning the previous state).
   The original reads the volatile global once more after the store (lw $a0, dead). */
extern "C" s32 func_0054C6E8(s32 v) {
    s32 st = func_005B72A8();
    s32 old = D_0064C3F0;
    D_0064C3F0 = v;
    (void)D_0064C3F0;
    if (st) __asm__ volatile("ei");
    return old;
}
