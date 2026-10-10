typedef int s32;

extern "C" void func_0021C9D8(void *arg0);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mModelStream__vtable;
extern void *mStream__vtable;

struct mStream__structor_1_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void mStream__structor_1(struct mStream__structor_1_arg0 *arg0, s32 arg1) {
    arg0->unk4 = &mModelStream__vtable;
    func_0021C9D8(arg0);
    arg0->unk4 = &mStream__vtable;
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x2C, 4, "RefCounter");
    }
}
