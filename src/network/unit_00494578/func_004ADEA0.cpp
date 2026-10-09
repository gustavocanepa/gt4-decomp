typedef int s32;
typedef unsigned int u32;

extern "C" void func_004ADE08(s32 arg0, u32 arg1);

extern "C" void func_004ADEA0(void) {
    func_004ADE08(1, 0xFFFF);
}
