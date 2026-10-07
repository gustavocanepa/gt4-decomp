typedef int s32;
typedef unsigned int u32;

extern "C" void func_00100C78(s32 arg0, u32 arg1);

extern "C" void func_00100CF0(void) {
    func_00100C78(0, 0xFFFF);
}
