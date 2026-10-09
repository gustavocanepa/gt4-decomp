typedef int s32;
typedef long long s64;

struct S0037D260 {
    char pad1[0x268];
    s64 unk268;
    char pad2[0x2C4 - 0x270];
    s32 unk2C4;
};

extern "C" void func_0037D260(S0037D260 *arg0, s32 arg1, s32 arg2) {
    arg0->unk2C4 = arg1;
    arg0->unk268 = (arg0->unk268 & ~(0xFFLL << 8)) | ((s64)(arg2 & 0xFF) << 8);
}
