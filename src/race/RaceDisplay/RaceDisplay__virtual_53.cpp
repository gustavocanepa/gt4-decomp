#include "gt4/RaceDisplay.h"
typedef int s32;

extern "C" void func_003A4F00(void *arg0, float arg1);
extern "C" void func_003A68C8(char *arg0);

extern "C" void RaceDisplay__virtual_53(struct RaceDisplay *arg0) {
    func_003A4F00((char *)arg0 + 0x17BC, 0.0f);
    func_003A68C8((char *)arg0 + 0x2D14);
}
