#include "gt4/stdiobuf.h"
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): stdiobuf::~stdiobuf.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

extern void *stdiobuf__vtable;
extern "C" void _IO_do_write(void *, void *, s32);
extern "C" void filebuf__structor_3(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void stdiobuf__structor_2(void *arg0, s32 arg1) {
    ((struct stdiobuf *)arg0)->unk50 = &stdiobuf__vtable;
    _IO_do_write(arg0, ((struct stdiobuf *)arg0)->unk10, ((s32)*(void **)((char *)arg0 + 0x14) - (s32)*(void **)((char *)arg0 + 0x10)));
    filebuf__structor_3(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
