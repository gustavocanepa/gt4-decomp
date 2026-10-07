typedef int s32;

extern "C" s32 func_003AEAE8(s32 arg0);

extern "C" s32 func_003DCF88(s32 arg0) {
    s32 temp = func_003AEAE8(arg0);
    return (temp == 0) ? arg0 : temp;
}
