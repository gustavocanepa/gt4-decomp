typedef int s32;

extern "C" s32 DisplayRText__getRTextStr(s32 arg0);

extern "C" s32 func_003DCF88(s32 arg0) {
    s32 temp = DisplayRText__getRTextStr(arg0);
    return (temp == 0) ? arg0 : temp;
}
