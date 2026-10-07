typedef int s32;

extern "C" void func_00504528(void *arg0);

extern "C" void func_00501180(void *arg0) {
    char *p = (char *)arg0 + 0x4C;
    for (s32 i = 15; i >= 0; i--) {
        func_00504528(p);
        p += 8;
    }
}
