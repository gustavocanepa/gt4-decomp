typedef int s32;
typedef short s16;

struct Obj {
    char pad0[0xE];
    s16 unkE;
    char pad1[0x54 - 0x10];
    s32 unk54;
};

extern "C" s32 func_005AADB0(s32 arg0, s16 arg1);

extern "C" s32 func_005A5CD0(struct Obj *arg0) {
    return func_005AADB0(arg0->unk54, arg0->unkE);
}
