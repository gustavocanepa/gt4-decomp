typedef int s32;
typedef unsigned int u32;

extern "C" void func_001BD920(s32 arg0, u32 arg1);

extern "C" void func_001BE020(void) {
    func_001BD920(1, 0xFFFF);
}
