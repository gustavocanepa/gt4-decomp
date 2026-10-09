typedef int s32;

extern "C" void func_003FABA0(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_00372050(s32 arg0, s32 arg1, s32 arg2) {
    s32 k = 0x19C;
    func_003FABA0(arg0 + arg1 * k + 0xE0, arg2, 1);
}
