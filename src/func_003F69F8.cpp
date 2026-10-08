typedef int s32;

extern "C" s32 func_003577F0(s32 **arg0);

extern "C" s32 func_003F69F8(s32 **arg0) {
    s32 result = func_003577F0(arg0);
    return (result < 4) ? result : 0;
}
