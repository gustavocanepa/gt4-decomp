typedef int s32;

extern "C" void func_002AE968(void *arg0, int arg1);
extern "C" void func_002AE9C0(void *arg0, void *arg1);
extern "C" void mListBox__leaveDragMode(s32 arg0, s32 arg1);
extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" void func_0022AD20(void *arg0, void *arg1);

extern "C" void MListBox__leaveDragMode(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s0 = arg3;

    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_002AE9C0(buf0, (void *)arg1);
        s32 *p1 = buf1;
        func_0022AD20(p1, (void *)s0);
        mListBox__leaveDragMode(buf0[0], p1[0]);
        func_0022ACC8(p1, 2);
        func_002AE968(buf0, 2);
    }
}
