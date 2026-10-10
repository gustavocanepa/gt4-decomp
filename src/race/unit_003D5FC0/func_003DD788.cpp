typedef unsigned int u32;
typedef int s32;

extern "C" s32 func_003DD788(u32 *p, u32 v) {
    u32 cur = *p;
    if (cur == 0x157529FF || v < cur) {
        if (v > 0x157529FF) v = 0x157529FF;
        *p = v;
        return 1;
    }
    return 0;
}
