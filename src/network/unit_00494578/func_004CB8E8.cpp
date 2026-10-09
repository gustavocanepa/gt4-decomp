typedef int s32;

struct Obj {
    char pad[0x60];
    s32 unk60;
    char pad2[0xC];
    s32 unk70;
};

extern "C" s32 func_004CB8E8(Obj *arg0, s32 arg1) {
    s32 shift = arg0->unk70;
    arg1 = arg1 - 2;
    return (arg1 << shift) + arg0->unk60;
}
