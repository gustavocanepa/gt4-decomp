typedef int s32;
typedef unsigned int u32;

extern "C" void func_001A9930(s32 arg0, u32 arg1);

extern "C" void func_001AA030(void) {
    func_001A9930(1, 0xFFFF);
}
