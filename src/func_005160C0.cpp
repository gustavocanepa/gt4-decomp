typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef void (*Fn)(u32, s32);

extern "C" u8 *func_00515DD8(s32 arg1);
extern "C" Fn D_008541F0[];

extern "C" void func_005160C0(u32 arg0, s32 arg1) {
    if (arg0 < 0x40) {
        u8 *p = func_00515DD8(arg1);
        if (p != 0) {
            Fn fn = D_008541F0[*p];
            if (fn != 0) {
                fn(arg0, arg1);
            }
        }
    }
}
