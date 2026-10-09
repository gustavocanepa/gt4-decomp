typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern "C" void func_001D4B58(char *arg0, s32 arg1, s32 arg2) {
    u8 *p1;
    s8 *p0;
    s8 t;

    p0 = (s8 *)(arg0 + arg1);
    p1 = (u8 *)(arg0 + arg2);
    t = *p0;
    *p0 = (s8)*p1;
    *p1 = (u8)t;
}
