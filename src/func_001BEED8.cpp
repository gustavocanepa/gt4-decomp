typedef int s32;
typedef unsigned int u32;

extern "C" void func_001BE818(s32 arg0, u32 arg1);

extern "C" void func_001BEED8(void) {
    func_001BE818(0, 0xFFFF);
}
