typedef int s32;

extern "C" s32 mWidget__getWindowW(void *arg0);
extern "C" s32 mWidget__getWindowH(void *arg0);

extern "C" s32 func_002E9790(char *arg0) {
    if (*(s32 *)(arg0 + 0xC4) != 0) {
        return mWidget__getWindowW(arg0);
    }
    return mWidget__getWindowH(arg0);
}
