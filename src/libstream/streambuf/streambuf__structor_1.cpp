#include "gt4/streambuf.h"
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streambuf::~streambuf.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

extern void *streambuf__vtable;
extern "C" void _IO_default_finish(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void streambuf__structor_1(struct streambuf *arg0, s32 arg1) {
    arg0->unk50 = &streambuf__vtable;
    _IO_default_finish(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
