typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x31];
    u8 unk31;
};

extern "C" s32 func_003F4EA0(Obj *arg0) {
    return *(s32 *)(0x622430 + (arg0->unk31 * 4));
}
