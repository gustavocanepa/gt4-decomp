typedef int s32;

extern "C" void func_003285A8(s32 arg0);

extern "C" void func_00328768(s32 *arg0, s32 *arg1) {
    s32 temp_v0 = *arg1;

    *arg0 = temp_v0;
    if (temp_v0 != 0) {
        func_003285A8(temp_v0);
    }
}
