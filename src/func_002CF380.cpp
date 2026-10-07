typedef int s32;
typedef unsigned int u32;

extern "C" void func_002CEC80(s32 arg0, u32 arg1);

extern "C" void func_002CF380(void) {
    func_002CEC80(1, 0xFFFF);
}
