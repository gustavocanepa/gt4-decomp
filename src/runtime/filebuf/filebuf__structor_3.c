/* libio (GNU iostream library, gcc 2000-10-03 snapshot): filebuf::~filebuf.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#include "gt4/filebuf.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 streambuf__structor_1(void *, s32);             /* extern */
s32 func_0059B038(void *, s32, s32);                    /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char filebuf__vtable[];
void filebuf__structor_3(struct filebuf *arg0, s32 arg1) {
    s32 temp_a1;

    arg0->unk50 = (void *)(s32)filebuf__vtable;
    if (arg0->unk38 >= 0) {
        temp_a1 = arg0->unk10;
        func_0059B038(arg0, temp_a1, arg0->unk14 - temp_a1);
        if (!(arg0->unk0 & 0x40)) {
            M2C_FIELD(arg0->unk50, s32 (**)(void *), 0x84)(arg0);
        }
    }
    streambuf__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
