typedef int s32;

extern "C" s32 DisplayRText__getRTextStr(s32 arg0);

extern "C" s32 func_003EBE28(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = DisplayRText__getRTextStr(arg1);
    return (temp_v0 == 0) ? arg1 : temp_v0;
}
