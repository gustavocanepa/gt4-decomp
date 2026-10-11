/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_cleanup.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 _IO_flush_all();                            /* extern */
s32 _IO_unbuffer_all();                            /* extern */

void _IO_cleanup(void) {
    _IO_flush_all();
    _IO_unbuffer_all();
}
