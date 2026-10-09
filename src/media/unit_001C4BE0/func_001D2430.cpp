typedef int s32;
typedef unsigned int u32;

extern "C" void func_001D1D90(s32 arg0, u32 arg1);

extern "C" void func_001D2430(void) {
    func_001D1D90(1, 0xFFFF);
}
