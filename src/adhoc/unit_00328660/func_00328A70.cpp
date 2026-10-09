typedef int s32;

struct Obj {
    char pad0[0x40];
    s32 unk40;
    s32 unk44;
};

extern "C" s32 func_00328A70(Obj *arg0) {
    return arg0->unk40 * arg0->unk44;
}
