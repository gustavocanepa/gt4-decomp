typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    u32 unk4;
    s32 unk8;
};

extern "C" void func_0060F3C8(Obj *arg0, s32 arg1) {
    u32 v = arg0->unk4 + arg1;
    if (v >= 8U) {
        v = v - 8;
    }
    arg0->unk8 = arg0->unk8 - arg1;
    arg0->unk4 = v;
}
