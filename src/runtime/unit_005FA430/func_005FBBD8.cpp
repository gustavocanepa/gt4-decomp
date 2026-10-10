typedef int s32;

extern "C" void RaceEventQueue__get(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_005FBBD8(s32 arg0, s32 arg1, s32 arg2) {
    RaceEventQueue__get(arg0 + 0xF4, arg1, arg2, 1);
}
