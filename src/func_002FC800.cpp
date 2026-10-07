typedef int s32;
typedef unsigned int u32;

extern "C" void func_002FC160(s32 arg0, u32 arg1);

extern "C" void func_002FC800(void) {
    func_002FC160(1, 0xFFFF);
}
