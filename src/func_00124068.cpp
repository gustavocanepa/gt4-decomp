typedef int s32;
typedef unsigned int u32;

extern "C" void func_00123968(s32 arg0, u32 arg1);

extern "C" void func_00124068(void) {
    func_00123968(1, 0xFFFF);
}
