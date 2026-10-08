typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

struct Inner {
    char pad0[0x262];
    u16 unk262;
};

struct Obj {
    char pad0[0x10];
    Inner *unk10;
    char pad1[0x5FE - 0x14];
    s16 unk5FE;
    char pad2[0x625 - 0x600];
    u8 unk625;
};

extern "C" s32 func_003F3758(Obj *arg0) {
    s32 result;

    result = 0;
    if (arg0->unk10->unk262 < arg0->unk5FE || arg0->unk625 != 0) {
        result = 1;
    }
    return result;
}
