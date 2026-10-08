typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad0[0x94];
    u8 unk94;
};

extern "C" s32 func_006036E0(Obj *arg0) {
    return arg0->unk94 * 10;
}
