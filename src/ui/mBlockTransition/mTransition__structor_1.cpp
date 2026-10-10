typedef int s32;

extern "C" void func_0027AEB0(void *arg0);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mBlockTransition__vtable;
extern void *mTransition__vtable;

struct mTransition__structor_1_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void mTransition__structor_1(struct mTransition__structor_1_arg0 *arg0, s32 arg1) {
    arg0->unk4 = &mBlockTransition__vtable;
    func_0027AEB0(arg0);
    arg0->unk4 = &mTransition__vtable;
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x3C, 4, "RefCounter");
    }
}
