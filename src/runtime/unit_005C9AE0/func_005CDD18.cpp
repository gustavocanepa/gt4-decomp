typedef unsigned char u8;
typedef int s32;

extern "C" void func_005CDD18(u8 *arg0, s32 arg1, u8 *arg2) {
    while (arg0 != (u8 *)arg1) {
        *arg0 = *arg2;
        arg0++;
    }
}
