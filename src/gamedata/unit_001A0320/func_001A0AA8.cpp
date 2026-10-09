typedef int s32;
typedef unsigned int u32;

extern "C" void func_001A0388(s32 arg0, u32 arg1);

extern "C" void func_001A0AA8(void) {
    func_001A0388(0, 0xFFFF);
}
