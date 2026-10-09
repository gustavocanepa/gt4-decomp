typedef int s32;

struct Obj4F4AF0 {
    char pad[0x3BFC];
    s32 unk3BFC;
};

extern "C" s32 func_004F4AF0(Obj4F4AF0 *arg0) {
    return arg0->unk3BFC != 0;
}
