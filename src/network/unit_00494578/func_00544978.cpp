typedef unsigned int u32;
typedef int s32;

extern "C" void func_00544978(u32 *arg0, u32 arg1) {
    u32 mask = 1u << arg1;
    arg0 += arg1 >> 5;
    *arg0 |= mask;
}
