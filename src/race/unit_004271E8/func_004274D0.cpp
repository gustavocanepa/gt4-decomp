typedef signed char s8;
typedef int s32;

struct Obj {
    s8 unk0;
    char pad1[0x40 - 1];
    s32 unk40;
};

extern "C" void func_004274D0(Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unk40 = 0;
}
