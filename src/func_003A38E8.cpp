typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad0[8];
    s32 unk8;
    s32 unkC;
};

extern "C" void func_003A38E8(Obj *arg0, u32 arg1) {
    arg0->unk8 = (s32)(arg1 & 0xF);
    arg0->unkC = (s32)(arg1 >> 4);
}
