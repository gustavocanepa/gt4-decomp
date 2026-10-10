typedef int s32;

extern "C" s32 mWidget__getWindowW(void *arg0);
extern "C" s32 mWidget__getWindowH(void *arg0);

extern "C" s32 mListBox__get_width(char *arg0) {
    if (*(s32 *)(arg0 + 0xB0) == 0) {
        return mWidget__getWindowW(arg0);
    }
    return mWidget__getWindowH(arg0);
}
