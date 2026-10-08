typedef unsigned char u8;
typedef int s32;

struct Obj {
    char pad[0x494];
    u8 unk494;
};

extern "C" s32 func_0043F4A8(s32 arg0, s32 arg1) {
    s32 idx = arg1 >> 3;
    u8 b = ((Obj *)(idx + arg0))->unk494;
    return (b >> (arg1 & 7)) & 1;
}
