typedef short s16;
typedef int s32;

extern "C" s16 *func_005C15B0(s32 arg0);

extern "C" void func_00476630(s32 arg0) {
    *func_005C15B0(arg0 + 4) = 0;
}
