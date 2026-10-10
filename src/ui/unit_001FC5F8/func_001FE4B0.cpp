typedef int s32;
extern "C" void func_0054EFD8(char *a);
extern "C" void func_001FE4B0(char *arg0) {
    *(s32 *)(arg0 + 0x84) = 0;
    char *p = *(char **)(arg0 + 0xB4);
    *(s32 *)(arg0 + 0x88) = 0;
    if (p) func_0054EFD8(p);
}
