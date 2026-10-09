typedef int s32;

extern s32 D_008468D4;

extern "C" void func_00575DA0(s32 arg0);

extern "C" void func_00460EA8(void) {
    s32 temp_v1 = D_008468D4;
    if (temp_v1 != 0) {
        func_00575DA0(temp_v1);
    }
}
