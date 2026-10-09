typedef int s32;
typedef unsigned int u32;

extern "C" void func_001C0EE0(s32 arg0, u32 arg1);

extern "C" void func_001C1600(void) {
    func_001C0EE0(0, 0xFFFF);
}
