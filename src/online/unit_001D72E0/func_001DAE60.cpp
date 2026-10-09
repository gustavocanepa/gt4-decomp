typedef int s32;
typedef unsigned int u32;

extern "C" void func_001DA760(s32 arg0, u32 arg1);

extern "C" void func_001DAE60(void) {
    func_001DA760(1, 0xFFFF);
}
