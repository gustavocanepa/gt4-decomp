#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004D91A8();                                /* extern */

extern char D_004D8C88[];
extern char D_004D9138[];
struct func_004D8BC8_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

s32 func_004D8BC8(struct func_004D8BC8_arg0 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 0x27;
    case 24:
        arg0->unk8 = 0x27;
        arg0->unk0 = (s32)D_004D9138;
        return 0x2D;
    case 36:
        arg0->unk8 = 0x27;
        arg0->unk0 = (s32)D_004D9138;
        return 0x2E;
    case 21:
        arg0->unk0 = (s32)D_004D8C88;
        return 0x27;
    default:
        return func_004D91A8();
    }
}
