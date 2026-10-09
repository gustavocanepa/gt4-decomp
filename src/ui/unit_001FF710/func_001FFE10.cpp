typedef int s32;
typedef unsigned int u32;

extern "C" void func_001FF710(s32 arg0, u32 arg1);

extern "C" void func_001FFE10(void) {
    func_001FF710(1, 0xFFFF);
}
