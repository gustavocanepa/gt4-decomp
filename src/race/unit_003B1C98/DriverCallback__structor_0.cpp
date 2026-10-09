typedef int s32;

struct S {
    void *unk0;
    s32 unk4;
};

extern "C" void func_004574A0(S *arg0, s32 arg1);

extern S D_00845370;
extern char DriverCallback__vtable;

extern "C" void DriverCallback__structor_0(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            D_00845370.unk4 = 0;
            D_00845370.unk0 = &DriverCallback__vtable;
        }
        if (arg0 == 0) {
            D_00845370.unk0 = &DriverCallback__vtable;
            func_004574A0(&D_00845370, 0);
        }
    }
}
