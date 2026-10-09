typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

struct S { char pad[0x83]; u8 unk83; };

extern "C" u32 func_003F1E30(S *arg0, s32 arg1) {
    return (u32)(arg1 * arg0->unk83) >> 7;
}
