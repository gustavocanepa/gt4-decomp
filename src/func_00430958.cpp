typedef int s32;
typedef signed char s8;

extern "C" void func_00430958(void *arg0) {
    *(s32 *)arg0 = (*(s32 *)arg0 & ~0xF) | 0xFFF0;
    *((s8 *)arg0 + 2) = 0;
}
