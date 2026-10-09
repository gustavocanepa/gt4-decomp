typedef int s32;

extern void func_00503C90(s32);

extern "C" void func_00504528(s32 *arg0) {
    s32 temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        func_00503C90(temp_v0);
    }
}
