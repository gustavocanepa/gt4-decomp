typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
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
