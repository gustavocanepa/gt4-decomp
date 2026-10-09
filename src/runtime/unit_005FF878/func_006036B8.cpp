typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad0[0x92];
    u8 unk92;
};

extern "C" s32 func_006036B8(Obj *arg0) {
    return arg0->unk92 * 10;
}
