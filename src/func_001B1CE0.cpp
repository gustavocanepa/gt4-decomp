typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B15C0(s32 arg0, u32 arg1);

extern "C" void func_001B1CE0(void) {
    func_001B15C0(0, 0xFFFF);
}
