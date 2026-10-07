typedef int s32;
typedef unsigned int u32;

extern "C" void func_002B9010(s32 arg0, u32 arg1);

extern "C" void func_002B9710(void) {
    func_002B9010(1, 0xFFFF);
}
