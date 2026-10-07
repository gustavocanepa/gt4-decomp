typedef int s32;

extern "C" void func_00427680(s32 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = *arg0;
    *arg0 = (temp_v0 == 0) ? 0 : (temp_v0 + arg1);
}
