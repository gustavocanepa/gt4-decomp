typedef int s32;

extern "C" void func_002F9B38(void *arg0, s32 arg1);
extern "C" void func_00200C50(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *D_0065D480;

extern "C" void func_00192D30(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 4) = &D_0065D480;
    func_002F9B38((char *)arg0 + 0xE4, 2);
    func_00200C50(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x164, 4, "RefCounter");
    }
}
