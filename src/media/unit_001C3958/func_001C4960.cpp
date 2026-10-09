typedef int s32;
typedef unsigned int u32;

extern "C" void func_001C42C0(s32 arg0, u32 arg1);

extern "C" void func_001C4960(void) {
    func_001C42C0(1, 0xFFFF);
}
