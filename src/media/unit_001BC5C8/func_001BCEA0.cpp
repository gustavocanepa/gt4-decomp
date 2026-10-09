typedef int s32;
typedef unsigned int u32;

extern "C" void func_001BC780(s32 arg0, u32 arg1);

extern "C" void func_001BCEA0(void) {
    func_001BC780(0, 0xFFFF);
}
