typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_00490740(s32 arg0, u32 arg1) {
    if (arg1 >= 9u) {
        arg1 = 4u;
    }
    return *(s32 *)(0x6AE4A0 + (arg1 * 4));
}
