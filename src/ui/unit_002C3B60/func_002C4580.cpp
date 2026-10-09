typedef int s32;
typedef unsigned int u32;

extern "C" void func_002C3E80(s32 arg0, u32 arg1);

extern "C" void func_002C4580(void) {
    func_002C3E80(1, 0xFFFF);
}
