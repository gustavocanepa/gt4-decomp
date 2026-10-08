typedef int s32;
typedef signed char s8;

struct Obj {
    char pad[0x18];
    s8 *unk18;
    s8 *unk1C;
};

extern "C" void func_006053D0(struct Obj *arg0, s32 arg1, s8 arg2, s8 arg3) {
    arg0->unk1C[arg1] = arg2;
    arg0->unk18[arg1] = arg3;
}
