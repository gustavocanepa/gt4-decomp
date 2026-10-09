typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    char pad4[4];
    s32 unk8;
};

extern "C" void func_0060EBA0(Obj *arg0, s32 arg1) {
    u32 v = (u32)(arg0->unk0 + arg1);
    if (v >= 0x1000U) {
        v = v - 0x1000;
    }
    arg0->unk8 = arg0->unk8 + arg1;
    arg0->unk0 = v;
}
