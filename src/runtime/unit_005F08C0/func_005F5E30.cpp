typedef unsigned long long u64;
typedef int s32;

struct S005F5E30 {
    char pad0[0x268];
    u64 unk268;
    char pad1[0x2C4 - 0x270];
    s32 unk2C4;
};

extern "C" void func_005F5E30(struct S005F5E30 *arg0) {
    arg0->unk2C4 = -1;
    arg0->unk268 = arg0->unk268 & 0xFFFFFFFFFFFF00FFULL;
}
