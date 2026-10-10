#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578048();                            /* extern */

extern char D_00689B08[];
struct func_0055E398_arg0 {
    char pad0[0x2C];
    s32 unk2C;
    s32 unk30;
    char pad34[0x4];
    s32 unk38;
    char pad3C[0x3BC];
    s32 unk3F8;
};

s32 func_0055E398(void *arg0) {
    func_00578048();
    ((struct func_0055E398_arg0 *)arg0)->unk30 = 0x3B8;
    ((struct func_0055E398_arg0 *)arg0)->unk38 = (s32)D_00689B08;
    ((struct func_0055E398_arg0 *)arg0)->unk2C = (s32) (arg0 + 0x40);
    ((struct func_0055E398_arg0 *)arg0)->unk3F8 = 0;
}
