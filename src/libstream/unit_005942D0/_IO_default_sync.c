/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_default_sync.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 _IO_default_sync(void) {
    return 0;
}
