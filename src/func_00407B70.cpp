typedef int s32;

extern "C" s32 func_00407B10(void);
extern "C" void func_00407A40(void *arg0, s32 arg1);
extern "C" s32 func_003AEAE8(void *arg0);

extern "C" s32 func_00407B70(void) {
    register s32 temp_v0 asm("$5");
    s32 var_v0;

    temp_v0 = func_00407B10();
    var_v0 = 0;
    if (temp_v0 >= 0) {
        char sp[16];
        func_00407A40(sp, temp_v0 % 13);
        var_v0 = func_003AEAE8(sp);
    }
    return var_v0;
}
