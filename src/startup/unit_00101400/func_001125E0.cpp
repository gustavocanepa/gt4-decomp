typedef int s32;
typedef unsigned int u32;

extern "C" void func_00111F40(s32 arg0, u32 arg1);

extern "C" void func_001125E0(void) {
    func_00111F40(1, 0xFFFF);
}
