typedef int s32;
typedef unsigned int u32;

extern "C" void func_001BC780(s32 arg0, u32 arg1);

extern "C" void func_001BCE80(void) {
    func_001BC780(1, 0xFFFF);
}
