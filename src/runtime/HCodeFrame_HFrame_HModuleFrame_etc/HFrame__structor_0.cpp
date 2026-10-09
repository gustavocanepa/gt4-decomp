typedef int s32;

extern void *HFrame__vtable;
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void HFrame__structor_0(void *arg0, s32 arg1) {
    *(void **)(arg0) = &HFrame__vtable;
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x14, 0x4, "HFrame");
    }
}
