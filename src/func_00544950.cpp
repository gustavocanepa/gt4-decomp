typedef unsigned int u32;
typedef int s32;

extern "C" s32 func_00544950(u32 *arg0, u32 arg1) {
    u32 mask = 1u << arg1;
    arg0 += arg1 >> 5;
    arg1 = *arg0;
    return (mask & arg1) != 0;
}
