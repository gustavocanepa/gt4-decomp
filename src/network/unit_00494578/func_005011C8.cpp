typedef int s32;

extern "C" void func_005043A0(void *arg0);

extern "C" void func_005011C8(void *arg0) {
    char *p = (char *)arg0 + 0x4C;
    for (s32 i = 15; i >= 0; i--) {
        func_005043A0(p);
        p += 8;
    }
}
