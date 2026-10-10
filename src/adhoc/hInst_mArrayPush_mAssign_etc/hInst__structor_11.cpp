typedef int s32;

extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hInst__vtable;

struct hInst__structor_11_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void hInst__structor_11(struct hInst__structor_11_arg0 *arg0, s32 arg1) {
    arg0->unk4 = &hInst__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC, 4, "RefCounter");
    }
}
