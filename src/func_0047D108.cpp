typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

struct Obj0047D108 {
    char pad0[0x1C];
    u8 unk1C;
};

extern "C" s32 func_0047D108(s32 arg0, u32 arg1) {
    s32 var_v0 = 0;
    if (arg1 < 0x80U) {
        u32 byte = ((struct Obj0047D108 *)(arg1 + arg0))->unk1C;
        var_v0 = (byte >> 2) & 1;
    }
    return var_v0;
}
