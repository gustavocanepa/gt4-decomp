/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

u8 func_0058D110(u8);                               /* extern */

struct func_0058D1C8_arg0 {
    char pad0[0x1];
    u8 unk1;
    u8 unk2;
    u8 unk3;
    char pad4[0x1];
    u8 unk5;
    u8 unk6;
    u8 unk7;
};

void func_0058D1C8(struct func_0058D1C8_arg0 *arg0) {
    arg0->unk7 = func_0058D110(arg0->unk7);
    arg0->unk6 = func_0058D110(arg0->unk6);
    arg0->unk5 = func_0058D110(arg0->unk5);
    arg0->unk3 = func_0058D110(arg0->unk3);
    arg0->unk2 = func_0058D110(arg0->unk2);
    arg0->unk1 = func_0058D110(arg0->unk1);
}
