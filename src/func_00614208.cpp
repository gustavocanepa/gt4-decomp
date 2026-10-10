/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef unsigned char u8;

struct Inner {
    s32 unk0;
    void *res;
    char pad8[0x12];
    u8 busy;
};

struct Obj {
    Inner *inner;
};

extern "C" void func_00593020(void *res);

extern "C" s32 func_00614208(Obj *self) {
    Inner *in = self->inner;
    if (in->busy != 0) {
        return 0;
    }
    if (in->res != 0) {
        func_00593020(in->res);
    }
    return 1;
}
