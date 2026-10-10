#include "gt4/RaceDisplay.h"
typedef int s32;

extern "C" void RaceEventDisplay__clear(void *arg0, float arg1);
extern "C" void RaceCarIconDisplay__clear(char *arg0);

extern "C" void RaceDisplay__clear(struct RaceDisplay *arg0) {
    RaceEventDisplay__clear((char *)arg0 + 0x17BC, 0.0f);
    RaceCarIconDisplay__clear((char *)arg0 + 0x2D14);
}
