typedef int s32;

extern "C" void mWidget__getWindowGeometry(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern "C" void mWidget__getWindowSize(void *arg0, s32 arg1, s32 arg2) {
    mWidget__getWindowGeometry(arg0, (char *)arg0 + 0x34, 0, 0, arg1, arg2);
}
