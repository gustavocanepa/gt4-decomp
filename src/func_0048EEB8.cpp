typedef int s32;
typedef unsigned int u32;

extern "C" u32 func_0048ED30(s32);

extern "C" s32 func_0048EEB8(u32 *out, s32 key) {
    u32 v = func_0048ED30(key);
    if (v < 12) {
        *out = v;
        return 1;
    }
    return 0;
}
