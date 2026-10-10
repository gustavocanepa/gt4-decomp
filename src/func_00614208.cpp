/* compiler: ee-gcc2.96-no-strict-aliasing */
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
