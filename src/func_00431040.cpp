typedef int s32;

extern "C" s32 func_00430BC0(void *arg0);
extern "C" void *func_00430E58(void *arg0, char *arg1);
extern "C" int func_005A5A30(char *buf, int n, const char *fmt, ...);

extern "C" s32 func_00431040(void *ctx, const char *name, const char *fmt, s32 first, s32 last) {
    char buf[64];
    s32 i;
    for (i = first; i <= last; i++) {
        void *p;
        func_005A5A30(buf, 0x40, fmt, name, i);
        p = func_00430E58(ctx, buf);
        if (p == 0) {
            return 0;
        }
        if (func_00430BC0(p) == 0) {
            return 0;
        }
    }
    return 1;
}
