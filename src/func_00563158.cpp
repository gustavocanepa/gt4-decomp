typedef int s32;

extern "C" s32 func_00563198(s32 arg0);
extern "C" void func_00563258(s32 arg0);

extern "C" s32 func_00563158(s32 arg0) {
    s32 temp_s1 = func_00563198(arg0);
    func_00563258(arg0);
    return temp_s1;
}
