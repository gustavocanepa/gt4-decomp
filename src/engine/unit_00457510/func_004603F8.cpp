#include "types.h"
#define NULL 0
struct Elem { char pad[0x18]; };
struct Array { Elem *data; u32 count; };
extern "C" void func_00460388(Elem *, s32, s32);
extern "C" void func_004603F8(Array *self, s32 arg1, s32 arg2) {
    u32 i;
    self->data = (Elem *)((char *)self->data + arg1);
    for (i = 0; i < self->count; i++) {
        func_00460388(&self->data[i], arg1, arg2);
    }
}
