typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B3940(s32 arg0, u32 arg1);

extern "C" void func_001B4060(void) {
    func_001B3940(0, 0xFFFF);
}
