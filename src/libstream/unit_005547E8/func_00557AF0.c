/* Interrupt handler: passes its argument to func_00578480, then leaves through ExitHandler(),
   like func_00555290. */
#include "ee_kernel.h"
void func_00578480(int);
int func_00557AF0(int cause, int arg) {
    func_00578480(arg);
    ExitHandler();
    return 0;
}
