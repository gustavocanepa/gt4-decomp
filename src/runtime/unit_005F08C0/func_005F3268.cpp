typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad0[4];
    s32 unk4;
    s32 unk8;
};

extern "C" void func_005F3268(Obj *arg0, s32 arg1) {
    u32 v = (u32)(arg0->unk4 + arg1);
    if (v >= 4U) {
        v = v - 4;
    }
    arg0->unk8 = arg0->unk8 - arg1;
    arg0->unk4 = v;
}
