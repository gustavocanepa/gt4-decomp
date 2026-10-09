typedef int s32;
typedef short s16;

extern "C" s32 func_005927C8(s32 arg0, s16 arg1);

extern "C" s32 func_006143D8(s32 arg0, s32 arg1) {
    return func_005927C8(arg0, (s16)arg1);
}
