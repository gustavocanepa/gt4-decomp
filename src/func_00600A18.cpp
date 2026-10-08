typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    char pad4[4];
    s32 unk8;
};

extern "C" void func_00600A18(Obj *arg0, s32 arg1) {
    u32 v = (u32)(arg0->unk0 + arg1);
    if (v >= 0xB6AU) {
        v = v - 0xB6A;
    }
    arg0->unk8 = arg0->unk8 + arg1;
    arg0->unk0 = v;
}
