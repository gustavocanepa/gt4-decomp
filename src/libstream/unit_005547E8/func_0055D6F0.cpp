typedef short s16;
typedef int s32;
typedef long long s64;

struct __attribute__((aligned(8))) Obj {
    s64 unk0;
    char pad8[0x18 - 8];
    s16 unk18;
};

extern "C" void func_0055D6F0(Obj *arg0, s32 arg1) {
    arg0->unk18 = (s16)arg1;
    arg0->unk0 = (s64)1 << arg1;
}
