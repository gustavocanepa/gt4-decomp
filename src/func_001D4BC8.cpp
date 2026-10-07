typedef int s32;

extern "C" void func_005D2330(s32 a0, s32 a1, s32 a2, const char *fmt, void *args);
extern "C" void func_005D2370(s32 a0, s32 a1, s32 a2, const char *fmt, void *args);
extern "C" char D_001D4B58[];

extern "C" void func_001D4BC8(s32 a0, s32 a1, s32 a2, s32 arg3, s32 t0) {
    s32 buf[2];
    if (t0 == 0) {
        func_005D2330(a0, a1, a2, D_001D4B58, buf);
    } else {
        buf[0] = arg3;
        buf[1] = t0;
        func_005D2370(a0, a1, a2, D_001D4B58, buf);
    }
}
