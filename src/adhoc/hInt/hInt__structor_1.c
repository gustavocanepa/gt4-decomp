#include "types.h"
#include "gt4/hInt.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 hObject__structor_1();                            /* extern */

extern char hInt__vtable[];
struct hInt__structor_1_arg1 {
    u8 pad0[0x10];
    s32 unk10;
};

s32 hInt__structor_1(struct hInt *arg0, struct hInt__structor_1_arg1 *arg1) {
    hObject__structor_1();
    arg0->unk4_s32 = (s32)hInt__vtable;
    arg0->unk10 = (s32) arg1->unk10;
}
