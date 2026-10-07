typedef int s32;
typedef unsigned int u32;

extern "C" void func_004B0890(s32 arg0, u32 arg1);

extern "C" void func_004B0920(void) {
    func_004B0890(1, 0xFFFF);
}
