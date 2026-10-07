typedef int s32;

extern "C" void func_00105440(void *arg0, s32 arg1) {
    *(volatile s32 *)((char *)arg0 + 0x18) = arg1;
    *(volatile s32 *)((char *)arg0 + 0x8) = arg1;
    *(volatile s32 *)((char *)arg0 + 0x10) = 0;
}
