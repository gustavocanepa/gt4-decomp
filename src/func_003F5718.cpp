typedef int s32;

extern "C" void func_003F5718(char *arg0) {
    s32 *p = (s32 *)(arg0 + 0x1015C);
    s32 i = 5;

    do {
        i -= 1;
        *p = 0;
        p -= 1;
    } while (i >= 0);
}
