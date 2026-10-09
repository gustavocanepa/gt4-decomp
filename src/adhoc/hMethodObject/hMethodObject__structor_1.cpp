typedef int s32;

extern "C" void func_003038E0(void *arg0, s32 arg1);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hMethodObject__vtable;

extern "C" void hMethodObject__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &hMethodObject__vtable;
    func_003038E0((char *)arg0 + 0x14, 2);
    func_00309378((char *)arg0 + 0x10, 2);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
