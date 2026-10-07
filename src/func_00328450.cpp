typedef int s32;

struct S00328450 {
    char pad0[4];
    void *unk4;
};

extern "C" char D_00676958;
extern "C" char D_0069ECB8[];

extern "C" void func_00326798(struct S00328450 *arg0, s32 arg1, s32 arg2, void *arg3);

extern "C" void func_00328450(struct S00328450 *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk4 = &D_00676958;
    if (arg1) {
        func_00326798(arg0, 8, 4, D_0069ECB8);
        return;
    }
}
