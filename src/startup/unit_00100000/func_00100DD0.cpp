typedef int s32;
typedef unsigned int u32;

extern "C" void func_00100D10(s32 arg0, u32 arg1);

extern "C" void func_00100DD0(void) {
    func_00100D10(1, 0xFFFF);
}
