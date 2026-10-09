typedef int s32;

extern "C" s32 func_003AEAE8(s32 arg0);

extern "C" s32 func_003EBE28(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_003AEAE8(arg1);
    return (temp_v0 == 0) ? arg1 : temp_v0;
}
