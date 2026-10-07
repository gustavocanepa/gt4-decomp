typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B0328(s32 arg0, u32 arg1);

extern "C" void func_001B0A48(void) {
    func_001B0328(0, 0xFFFF);
}
