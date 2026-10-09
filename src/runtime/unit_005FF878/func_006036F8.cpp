typedef int s32;
typedef unsigned char u8;

struct Obj006036F8 {
    char pad0[0x95];
    u8 unk95;
};

extern "C" s32 func_006036F8(struct Obj006036F8 *arg0) {
    return arg0->unk95 * 0x64;
}
