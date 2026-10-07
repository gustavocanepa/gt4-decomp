typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B15C0(s32 arg0, u32 arg1);

extern "C" void func_001B1CC0(void) {
    func_001B15C0(1, 0xFFFF);
}
