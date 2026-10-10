typedef int s32;

extern const char **D_00621870;
extern char D_006A2368[];
extern "C" s32 func_0057DA20(char *, const char *, s32, const char *);

extern "C" void func_003B0370(char *buf, s32 unused, s32 n) {
    s32 idx = (n != 1) ? 0x4F : 0x4E;
    func_0057DA20(buf, D_006A2368, n, D_00621870[idx]);
}
