typedef int s32;
typedef unsigned int u32;

extern "C" void func_00101B20(s32 arg0, u32 arg1);

extern "C" void func_00101B78(void) {
    func_00101B20(1, 0xFFFF);
}
