typedef int s32;

struct Obj {
    char pad[0x4];
    s32 unk4;
};

extern "C" s32 func_00400BA8(Obj *arg0) {
    return arg0->unk4 >= 0xF1;
}
