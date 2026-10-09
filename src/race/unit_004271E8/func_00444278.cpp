typedef int s32;

extern "C" s32 func_004443A8(s32 arg0, s32 arg1);
extern "C" void func_004442B0(s32 arg0, s32 arg1);

extern "C" s32 func_00444278(s32 arg0, s32 arg1) {
    func_004442B0(arg0, arg1);
    return func_004443A8(arg0, arg1);
}
