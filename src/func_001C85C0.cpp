typedef int s32;
typedef unsigned int u32;

extern "C" void func_001C7F00(s32 arg0, u32 arg1);

extern "C" void func_001C85C0(void) {
    func_001C7F00(0, 0xFFFF);
}
