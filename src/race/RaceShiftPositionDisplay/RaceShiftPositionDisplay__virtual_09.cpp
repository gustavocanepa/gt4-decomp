#include "gt4/RaceShiftPositionDisplay.h"
typedef int s32;

extern "C" s32 func_003A1E10(const char *arg0);

extern "C" void RaceShiftPositionDisplay__virtual_09(struct RaceShiftPositionDisplay *arg0) {
    arg0->unk10 = func_003A1E10("gear_base");
}
