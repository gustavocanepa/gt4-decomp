typedef int s32;
typedef signed char s8;

extern "C" void func_003E29C8(char *arg0) {
    s8 *p = (s8 *)(arg0 + 0x5F);
    s32 i = 7;

    do {
        i -= 1;
        *p = 0;
        p -= 1;
    } while (i >= 0);
}
