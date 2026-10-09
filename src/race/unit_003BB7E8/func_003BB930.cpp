typedef int s32;

extern "C" s32 func_003BB978(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_003BB930(void *arg0, void *arg1, s32 arg2) {
    s32 off = arg2 * 4;
    s32 v1 = *(s32 *)((char *)arg1 + off);
    s32 v0 = *(s32 *)((char *)arg0 + off);
    return func_003BB978(v0, v1, off);
}
