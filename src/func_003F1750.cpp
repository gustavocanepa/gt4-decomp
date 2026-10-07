typedef int s32;
typedef unsigned char u8;

struct Obj3F1750 {
    char pad[0x1C2];
    u8 unk1C2;
};

extern "C" s32 func_003F1750(Obj3F1750 *arg0) {
    return arg0->unk1C2 == 0;
}
