typedef int s32;
typedef unsigned int u32;

extern "C" void func_002C2108(s32 arg0, u32 arg1);

extern "C" void func_002C2808(void) {
    func_002C2108(1, 0xFFFF);
}
