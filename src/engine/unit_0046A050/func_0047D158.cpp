typedef int s32;
typedef signed char s8;

struct Obj {
    char pad0[0x4];
    s32 unk4;
    char pad1[0x11C - 0x4 - 4];
    s32 unk11C;
};

extern "C" void func_0047D158(Obj *arg0, s8 arg1) {
    arg0->unk11C = 1;
    arg0->unk4 = (s32)arg1;
}
