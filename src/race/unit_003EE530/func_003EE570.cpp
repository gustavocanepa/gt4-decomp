typedef int s32;
typedef unsigned int u32;

extern "C" void func_003EE530(s32 arg0, u32 arg1);

extern "C" void func_003EE570(void) {
    func_003EE530(1, 0xFFFF);
}
