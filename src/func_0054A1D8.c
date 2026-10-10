/* Interrupt handler: signal the semaphore at most twice while enabled, then ExitHandler().
 * Sony's ExitHandler() is one asm block "sync.l; ei", which tools/asm_policy.py does not allow;
 * two single-instruction asms plus an empty volatile asm reproduce its scheduling (workaround). */
extern volatile int D_0064C3F0;
extern int D_0064C3F4;
extern int D_0064C3F8;
extern void func_00578480(int sema);

int func_0054A1D8(void) {
    if (D_0064C3F0) {
        int n = D_0064C3F4;
        if (n < 2) {
            D_0064C3F4 = n + 1;
            func_00578480(D_0064C3F8);
        }
    }
    __asm__ volatile("sync");
    __asm__ volatile("ei");
    __asm__ volatile("");
    return 0;
}
