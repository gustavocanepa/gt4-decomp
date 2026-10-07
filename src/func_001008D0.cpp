typedef int s32;
typedef unsigned int u32;

extern "C" void func_00100230(s32 arg0, u32 arg1);

extern "C" void func_001008D0(void) {
    func_00100230(1, 0xFFFF);
}
