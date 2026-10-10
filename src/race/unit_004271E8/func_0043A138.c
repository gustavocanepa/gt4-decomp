#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void AutomobileControl__clearPacket(s32);
void func_0043A138(s32 *arg0) {
    s32 i;
    if (arg0[0] != 0) {
        AutomobileControl__clearPacket(arg0[0]);
    }
    arg0[1] = 0;
    for (i = 3; i >= 0; i--) {
        arg0[2 + i] = 0;
    }
    arg0[6] = 0;
    arg0[7] = 0;
    arg0[8] = 0;
}
