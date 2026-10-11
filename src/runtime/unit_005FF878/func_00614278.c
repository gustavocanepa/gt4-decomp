/* libio (GNU iostream library, gcc 2000-10-03 snapshot): PlotFile::cmd?.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 _IO_putc(s8, s32);                     /* extern */

s32 **func_00614278(s32 **arg0, s8 arg1) {
    _IO_putc(arg1, **arg0);
    return arg0;
}
