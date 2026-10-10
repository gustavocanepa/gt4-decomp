typedef int s32;

extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_0030F808(void *arg0, s32 arg1);

extern void *hInst__vtable;
extern void *mUndef__vtable;

struct hInst__structor_31_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void hInst__structor_31(void *arg0, s32 arg1) {
    ((struct hInst__structor_31_arg0 *)arg0)->unk4 = &mUndef__vtable;
    func_0030F808((char *)arg0 + 8, 2);
    ((struct hInst__structor_31_arg0 *)arg0)->unk4 = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
