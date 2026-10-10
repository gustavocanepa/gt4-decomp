typedef int s32;

extern char D_00699020[];
extern char D_00699028[];

extern "C" s32 func_0057DA20(char *buf, const char *fmt, ...);
extern "C" s32 func_005B40A8(const char *path, s32 mode);

extern "C" bool func_00242CC0(void *self, const char *name) {
    char buf[0x80];
    func_0057DA20(buf, D_00699020, D_00699028, name);
    return func_005B40A8(buf, 0x1FD) == 0;
}
