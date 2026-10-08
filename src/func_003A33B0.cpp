typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    char pad4[4];
    s32 unk8;
};

extern "C" void func_003A33B0(Obj *arg0, u32 arg1) {
    arg0->unk0 = (s32)(arg1 & 0xF);
    arg0->unk8 = (s32)((arg1 >> 8) & 0x3FF);
}
