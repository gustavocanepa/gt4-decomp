/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): an out-of-line (linkonce) copy of a member of the C++ runtime's classes (type_info and its __*_type_info subclasses, exception, bad_alloc, bad_cast, bad_typeid, bad_exception: cp/tinfo.h, typeinfo, exception, new), from the block the runtime's objects brought (0x616370-0x616f24).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#include "types.h"
#include "gt4/type_info.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char type_info__vtable[];
s32 func_006163B0(struct type_info *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = (s32)type_info__vtable;
}
