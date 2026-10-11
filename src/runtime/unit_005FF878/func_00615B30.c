/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005C1628(void *);                      /* extern */
s32 func_005C1648(s32);                         /* extern */

extern char D_0068A148[];
struct func_00615B30_arg0 {
    char pad0[0x20];
    s32 unk20;
    char pad24[0x4];
    s32 unk28;
};

void func_00615B30(struct func_00615B30_arg0 *arg0, s32 arg1) {
    arg0->unk28 = (s32)D_0068A148;
    func_005C1648(arg0->unk20);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
