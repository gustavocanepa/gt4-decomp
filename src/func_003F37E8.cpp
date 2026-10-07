typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Obj {
    char pad[0x56B];
    u8 unk56B;
    char pad2[0x5B0 - 0x56C];
    s16 unk5B0;
};

extern "C" s32 func_003F37E8(struct Obj *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0->unk5B0 == 0) {
        var_v1 = arg0->unk56B == 1;
    }
    return var_v1;
}
