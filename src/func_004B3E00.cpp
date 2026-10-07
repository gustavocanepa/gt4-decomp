typedef int s32;
typedef unsigned int u32;

extern "C" void func_004B3DA0(s32 arg0, u32 arg1);

extern "C" void func_004B3E00(void) {
    func_004B3DA0(1, 0xFFFF);
}
