typedef int s32;
typedef long long s64;
typedef unsigned int u32;

struct Obj001CB8D8 {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_001CB8D8(Obj001CB8D8 *arg0, s64 arg1) {
    arg0->unk0 = (s32)(arg1 >> 32);
    arg0->unk4 = (s32)(arg1 & 0xFFFFFFFFU);
}
