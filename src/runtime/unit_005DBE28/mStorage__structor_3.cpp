typedef int s32;

extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mStorage__vtable;

struct mStorage__structor_3_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void mStorage__structor_3(struct mStorage__structor_3_arg0 *arg0, s32 arg1) {
    arg0->unk4 = &mStorage__vtable;
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x14, 4, "RefCounter");
    }
}
