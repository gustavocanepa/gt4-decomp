typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_005525F0(void);

extern "C" s32 func_00437928(void) {
    return (u32)(func_005525F0() - 1) < 2U;
}
