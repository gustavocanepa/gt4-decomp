typedef int s32;

extern "C" void func_00105450(void *arg0, s32 arg1) {
    *(volatile s32 *)((char *)arg0 + 0x1C) = arg1;
    *(volatile s32 *)((char *)arg0 + 0xC) = arg1;
    *(volatile s32 *)((char *)arg0 + 0x14) = 0;
}
