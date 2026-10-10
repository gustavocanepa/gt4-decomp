typedef int s32;

extern "C" void *func_00447E18(void *);
extern "C" void *func_00447BB8(void *);
extern "C" s32 SPEC_DATABASE__GetCarNameInfo(void *, void *);

extern "C" s32 func_004480D8(void *key, void *out) {
    void *p = func_00447E18(key);
    if (p == 0)
        return 0;
    return SPEC_DATABASE__GetCarNameInfo(func_00447BB8(p), out);
}
