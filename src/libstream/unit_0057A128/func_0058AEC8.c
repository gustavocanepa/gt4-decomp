/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0058AEC8_arg0 {
    u8 unk0;
    u8 unk1;
};

s32 func_0058AEC8(struct func_0058AEC8_arg0 *arg0) {
    if ((arg0->unk0 != 0x1F) || (arg0->unk1 != 0x8B)) {
        return 0;
    }
    return 1;
}
