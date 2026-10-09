typedef int s32;
typedef long long s64;

struct __attribute__((aligned(8))) Obj {
    s64 unk0;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern "C" void func_00572D30(Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unk8 = -0x20;
    arg0->unkC = 0;
    arg0->unk10 = 0;
}
