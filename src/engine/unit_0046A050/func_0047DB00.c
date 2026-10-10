#include "types.h"
#define NULL 0
void func_0047DB00(f32 *self, f32 x) {
    while (x > 0x1.68p+7f) {
        x -= 0x1.68p+8f;
    }
    while (x < -0x1.68p+7f) {
        x += 0x1.68p+8f;
    }
    self[11] = x * 0x1.1df468p-6f;
}
