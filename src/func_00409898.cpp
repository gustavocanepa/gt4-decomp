typedef int s32;

struct S {
    void *unk0;
    s32 unk4;
};

extern "C" void func_004574A0(S *arg0, s32 arg1);

extern S D_00845C20;
extern char D_00686328;

extern "C" void func_00409898(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            D_00845C20.unk4 = 0;
            D_00845C20.unk0 = &D_00686328;
        }
        if (arg0 == 0) {
            D_00845C20.unk0 = &D_00686328;
            func_004574A0(&D_00845C20, 0);
        }
    }
}
