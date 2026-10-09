typedef int s32;

extern "C" void func_00461FF8(s32 arg0);

extern s32 D_008434F0;

extern "C" void func_00335960(void) {
    D_008434F0 = 0x12345678;
    func_00461FF8(1);
}
