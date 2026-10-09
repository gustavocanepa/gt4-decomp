typedef int s32;
typedef unsigned int u32;

extern "C" void func_001B9D38(s32 arg0, u32 arg1);

extern "C" void func_001BA438(void) {
    func_001B9D38(1, 0xFFFF);
}
