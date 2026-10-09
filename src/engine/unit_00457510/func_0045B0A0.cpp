typedef int s32;
typedef unsigned char u8;

extern "C" void func_0045AF18(s32 arg0, u8 arg1);

extern "C" void func_0045B0A0(s32 arg0, u8 *arg1, s32 arg2) {
    s32 count = arg2;
    u8 *p = arg1;

    if (count != 0) {
        do {
            u8 c = *p;
            p += 1;
            count -= 1;
            func_0045AF18(arg0, c);
        } while (count != 0);
    }
}
