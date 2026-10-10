typedef int s32;
typedef unsigned int u32;
s32 func_005AE0B0(s32 a);
s32 func_005B7120(void) {
    u32 r = func_005AE0B0(4) & 0x10000;
    return r != 0;
}
