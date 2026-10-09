typedef int s32;
typedef unsigned int u32;

extern "C" void func_003DEC50(s32 arg0, u32 arg1);

extern "C" void func_003DEE30(void) {
    func_003DEC50(1, 0xFFFF);
}
