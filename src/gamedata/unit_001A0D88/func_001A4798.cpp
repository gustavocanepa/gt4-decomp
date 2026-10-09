typedef int s32;
typedef unsigned int u32;

extern "C" void func_001A4098(s32 arg0, u32 arg1);

extern "C" void func_001A4798(void) {
    func_001A4098(1, 0xFFFF);
}
