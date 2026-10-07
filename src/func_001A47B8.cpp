typedef int s32;
typedef unsigned int u32;

extern "C" void func_001A4098(s32 arg0, u32 arg1);

extern "C" void func_001A47B8(void) {
    func_001A4098(0, 0xFFFF);
}
