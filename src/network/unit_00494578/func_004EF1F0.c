#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004EF168();                            /* extern */
void func_004EF690(void *);                      /* extern */

struct func_004EF1F0_arg0 {
    s32 unk0;
    char pad4[0x90];
    s32 unk94;
    s32 unk98;
};

void func_004EF1F0(struct func_004EF1F0_arg0 *arg0) {
    if (arg0->unk0 != 0) {
        func_004EF168();
        func_004EF690(arg0);
        arg0->unk94 = -1;
        arg0->unk98 = 0;
    }
}
