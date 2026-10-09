typedef int s32;
typedef unsigned int u32;

extern "C" void func_001A0388(s32 arg0, u32 arg1);

extern "C" void func_001A0A88(void) {
    func_001A0388(1, 0xFFFF);
}
