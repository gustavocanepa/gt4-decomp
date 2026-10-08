typedef unsigned char u8;
typedef signed char s8;

struct Inner_00364FB8 {
    char pad0[0x29];
    u8 unk29;
};

struct Struct_00364FB8 {
    Inner_00364FB8 *unk0;
    u8 unk4;
};

typedef int s32;

extern "C" s32 func_00364FB8(struct Struct_00364FB8 *arg0, s8 *arg1, s8 *arg2) {
    if (arg0->unk4 != 0) {
        return 0;
    }
    *arg1 = 0;
    *arg2 = 0x5A;
    return arg0->unk0->unk29;
}
