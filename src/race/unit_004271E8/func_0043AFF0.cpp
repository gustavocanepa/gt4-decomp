typedef int s32;
typedef unsigned int u32;

extern "C" void func_0043AFF0(char *arg0, u32 arg1) {
    if (arg1 < 7U) {
        char *base = (char *)(arg1 * 4 + (u32)arg0);
        s32 *p = (s32 *)(base + 0x54);
        *p = *p + 1;
    }
}
