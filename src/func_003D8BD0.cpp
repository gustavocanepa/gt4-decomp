typedef int s32;

struct Obj {
    char pad[0x60];
    s32 unk60;
    s32 unk64;
};

extern "C" s32 func_003D8BD0(Obj *arg0) {
    return arg0->unk64 == arg0->unk60;
}
