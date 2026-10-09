typedef int s32;
typedef unsigned int u32;

extern "C" void func_004AFFF0(s32 arg0, u32 arg1);

extern "C" void func_004B0048(void) {
    func_004AFFF0(1, 0xFFFF);
}
