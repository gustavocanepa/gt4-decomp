typedef int s32;

extern "C" s32 func_003D28A0(s32 arg0);

extern "C" s32 RacePS2Base__virtual_136(s32 arg0) {
    return func_003D28A0(arg0 + 0x3628) != 0;
}
