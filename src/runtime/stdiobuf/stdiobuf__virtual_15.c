/* libio (GNU iostream library, gcc 2000-10-03 snapshot): stdiobuf::sys_close.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
#include "gt4/stdiobuf.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005A31F0(s32);                         /* extern */

void stdiobuf__virtual_15(struct stdiobuf *arg0) {
    func_005A31F0(arg0->unk58);
    arg0->unk58 = 0;
}
