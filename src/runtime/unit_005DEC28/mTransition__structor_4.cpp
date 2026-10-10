typedef int s32;

extern void *mTransition__vtable;
extern "C" void hObject__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

struct mTransition__structor_4_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void mTransition__structor_4(struct mTransition__structor_4_arg0 *arg0, s32 arg1) {
    arg0->unk4 = &mTransition__vtable;
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x40, 0x4, "RefCounter");
    }
}
