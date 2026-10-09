typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    char pad4[0x8 - 0x4];
    s32 unk8;
};

extern "C" void func_0060F378(Obj *arg0, s32 arg1) {
    u32 v = (u32)(arg0->unk0 + arg1);
    if (v >= 8U) {
        v = v - 8;
    }
    arg0->unk8 = arg0->unk8 + arg1;
    arg0->unk0 = v;
}
