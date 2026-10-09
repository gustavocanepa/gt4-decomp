typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B91B8(s32 arg0, u32 arg1);

extern "C" void func_001B98B8(void) {
    func_001B91B8(1, 0xFFFF);
}
