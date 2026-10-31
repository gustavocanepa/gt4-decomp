/* Interrupt handler: while the counter D_00654A3C is below 2, counts one more and calls
   func_00578480 on D_00654A40; leaves through ExitHandler(). */
#include "ee_kernel.h"
extern int D_00654A3C;
extern int D_00654A40;
void func_00578480(int);
int func_0055EB08(void) {
    int n = D_00654A3C;
    if (n < 2) {
        D_00654A3C = n + 1;
        func_00578480(D_00654A40);
    }
    ExitHandler();
    return 0;
}
