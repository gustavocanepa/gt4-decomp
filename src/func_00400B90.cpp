typedef int s32;

struct Obj {
    char pad0[0x1C];
    s32 unk1C;
};

extern "C" s32 func_00400B90(Obj *arg0) {
    return arg0->unk1C > 0;
}
