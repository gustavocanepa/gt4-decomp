typedef int s32;

extern "C" void func_002AE968(void *arg0, int arg1);
extern "C" void func_002AE9C0(void *arg0, void *arg1);
extern "C" s32 mListBox__get_total_item_count(char *arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void MListBox__getItemCount(s32 *arg0, void *arg1, s32 arg2) {
    char *h[4];
    if (arg2 == 0) {
        s32 buf[4];
        s32 *buf0;
        s32 newVal;
        s32 oldVal;
        s32 v;
        func_002AE9C0(h, arg1);
        v = mListBox__get_total_item_count(h[0]);
        buf0 = buf;
        func_002FE278(buf0, v);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(buf0, 2);
        func_002AE968(h, 2);
    }
}
