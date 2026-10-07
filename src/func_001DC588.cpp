typedef int s32;
typedef unsigned int u32;

extern "C" void func_001DBE88(s32 arg0, u32 arg1);

extern "C" void func_001DC588(void) {
    func_001DBE88(1, 0xFFFF);
}
