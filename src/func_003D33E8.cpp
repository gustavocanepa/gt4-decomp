typedef int s32;

struct S {
    void *unk0;
    s32 unk4;
};

extern "C" void func_004574A0(S *arg0, s32 arg1);

extern S D_00845680;
extern char D_006829D0;

extern "C" void func_003D33E8(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            D_00845680.unk4 = 0;
            D_00845680.unk0 = &D_006829D0;
        }
        if (arg0 == 0) {
            D_00845680.unk0 = &D_006829D0;
            func_004574A0(&D_00845680, 0);
        }
    }
}
