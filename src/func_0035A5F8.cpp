typedef int s32;
typedef signed char s8;

extern "C" void func_0035A5F8(char *arg0, s32 arg1, s8 arg2) {
    if (arg1 < 4) {
        char *base = arg0 + arg1;
        *(s8 *)(base + 0x774) = arg2;
    }
}
