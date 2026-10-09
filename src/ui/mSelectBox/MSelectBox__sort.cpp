typedef int s32;

extern "C" void func_002D8B08(s32 *arg0);
extern "C" void func_002F9B90(s32 *arg0, s32 arg1);
extern "C" void func_002DBF20(s32 arg0, s32 *arg1);
extern "C" void func_002F9B38(s32 *arg0, s32 arg1);
extern "C" void func_002D8AB0(s32 *arg0, s32 arg1);

extern "C" void MSelectBox__sort(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_002D8B08(buf0);
        func_002F9B90(buf1, arg3);
        func_002DBF20(buf0[0], buf1);
        func_002F9B38(buf1, 2);
        func_002D8AB0(buf0, 2);
    }
}
