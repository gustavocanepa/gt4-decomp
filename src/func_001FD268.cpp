typedef int s32;
typedef unsigned int u32;

extern "C" void func_001FCB68(s32 arg0, u32 arg1);

extern "C" void func_001FD268(void) {
    func_001FCB68(1, 0xFFFF);
}
