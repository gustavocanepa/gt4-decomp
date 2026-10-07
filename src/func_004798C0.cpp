typedef int s32;
typedef short s16;

struct Obj004798B0 {
    char pad[0x12];
    s16 unk12;
    s16 unk14;
};

extern "C" s32 func_004798C0(struct Obj004798B0 *arg0) {
    return arg0->unk12 + arg0->unk14;
}
