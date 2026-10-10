typedef int s32;

extern "C" s32 func_004334F8();
extern "C" void GranTurismo4__GetTimeString(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_00433558(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    GranTurismo4__GetTimeString(func_004334F8(), arg2, arg3);
}
