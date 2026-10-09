typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B6150(s32 arg0, u32 arg1);

extern "C" void func_001B6870(void) {
    func_001B6150(0, 0xFFFF);
}
