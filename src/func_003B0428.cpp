typedef int s32;

extern "C" void func_005A609C(char *dst, const char *src);
extern "C" char *func_005A6AB0(char *dst, const char *src, s32 n);
extern "C" char D_006A2388[];

extern "C" void func_003B0428(char *dst, const char *src, s32 size) {
    if (src == 0) {
        src = D_006A2388;
    }
    if (size < 0) {
        return func_005A609C(dst, src);
    }
    func_005A6AB0(dst, src, size - 1);
    dst[size - 1] = 0;
}
