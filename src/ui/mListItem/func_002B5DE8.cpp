typedef int s32;
typedef unsigned int u32;

extern "C" void func_002B5678(s32 arg0, u32 arg1);

extern "C" void func_002B5DE8(void) {
    func_002B5678(1, 0xFFFF);
}
