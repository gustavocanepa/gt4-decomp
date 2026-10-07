typedef int s32;
typedef short s16;
typedef signed char s8;

struct Obj {
    char pad0[4];
    s8 *unk4;
    char pad1[0x5B0 - 8];
    s16 unk5B0;
};

extern "C" s32 func_00343BC0(struct Obj *arg0) {
    return arg0->unk5B0 + arg0->unk4[0xCBE5];
}
