typedef int s32;
typedef unsigned int u32;

extern "C" void func_001AE468(s32 arg0, u32 arg1);

extern "C" void func_001AEB68(void) {
    func_001AE468(1, 0xFFFF);
}
