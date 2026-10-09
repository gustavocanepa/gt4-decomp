typedef int s32;

extern "C" s32 func_0025A6F0(s32 arg0);
extern "C" void func_0025A8D0(s32 arg0, s32 arg1);

extern "C" s32 func_0025ACE8(s32 arg0, s32 arg1) {
    func_0025A8D0(arg0, func_0025A6F0(arg1));
    return arg0;
}
