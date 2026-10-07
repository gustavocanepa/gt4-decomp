typedef int s32;
typedef unsigned int u32;

extern "C" void func_003BCC08(s32 arg0, u32 arg1);

extern "C" void func_003BCC48(void) {
    func_003BCC08(1, 0xFFFF);
}
