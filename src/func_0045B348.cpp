typedef int s32;
typedef unsigned int u32;

extern "C" s32 func_00594470(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_0045B348(s32 arg0, s32 arg1) {
    return (u32)func_00594470(arg0, arg1, 4) < 1;
}
