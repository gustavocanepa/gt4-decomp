#include "types.h"
#define NULL 0
f32 func_00459338(f32 x) {
    if (x < -0x1.c2p+12f || x > 0x1.c2p+12f) {
        return 0.0f;
    }
    while (x < 0.0f) {
        x += 0x1.68p+8f;
    }
    while (x >= 0x1.68p+8f) {
        x -= 0x1.68p+8f;
    }
    return x;
}
