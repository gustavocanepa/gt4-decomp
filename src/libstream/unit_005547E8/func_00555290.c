/* Interrupt handler: passes its argument to func_005554B0, then leaves through the kernel header's
   ExitHandler() (one `sync.l; ei` statement, which keeps the return value ahead of `ld $ra`). */
#include "ee_kernel.h"
void func_005554B0(void *);
int func_00555290(int cause, void *arg) {
    func_005554B0(arg);
    ExitHandler();
    return 0;
}
