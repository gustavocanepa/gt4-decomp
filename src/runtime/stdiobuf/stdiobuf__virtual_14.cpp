#include "gt4/stdiobuf.h"
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): stdiobuf::sys_seek.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

extern "C" void fseek(s32 arg0);

extern "C" void stdiobuf__virtual_14(struct stdiobuf *arg0) {
    fseek(arg0->unk58);
}
