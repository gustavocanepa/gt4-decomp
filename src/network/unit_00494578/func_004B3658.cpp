typedef int s32;
typedef unsigned int u32;

extern "C" void func_004B3600(s32 arg0, u32 arg1);

extern "C" void func_004B3658(void) {
    func_004B3600(1, 0xFFFF);
}
