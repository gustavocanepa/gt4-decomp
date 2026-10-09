typedef int s32;

struct Obj {
    char pad0[0x40];
    s32 unk40;
    char pad1[0x8];
    s32 unk4C;
};

extern "C" s32 func_00328A60(Obj *arg0) {
    return arg0->unk40 * arg0->unk4C;
}
