typedef unsigned int u32;
typedef int s32;

struct S { char pad[0x98]; s32 unk98; };

extern "C" u32 func_002661C8(S *arg0) {
    return (u32)(arg0->unk98 & 0xF) >> 3;
}
