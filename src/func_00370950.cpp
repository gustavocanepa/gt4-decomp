typedef unsigned int u32;
typedef int s32;

struct S { char pad[0x40]; s32 unk40; };

extern "C" u32 func_00370950(S *arg0) {
    return (u32)(~arg0->unk40) >> 0x1F;
}
