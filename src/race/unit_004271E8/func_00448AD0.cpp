typedef int s32;
extern "C" long long func_00447BB8(const char *);
extern "C" long long func_00447C28(const char *);
extern "C" s32 func_00448B48(long long, void *);
extern "C" s32 func_00448AD0(const char *label, void *dest) {
    long long code = func_00447BB8(label);
    if (code == -1) {
        code = func_00447C28(label);
        if (code == -1) return 0;
    }
    return func_00448B48(code, dest);
}
