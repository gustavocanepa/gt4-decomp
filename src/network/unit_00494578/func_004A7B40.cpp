typedef float f32;
typedef int s32;

struct Regs {
    char pad[0xC30];
    f32 unkC30;
    s32 unkC34;
};

extern "C" void func_004A7B40(f32 fparg0) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    ptr->unkC30 = fparg0;
}

extern "C" void func_004A7B50(s32 arg0) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    ptr->unkC34 = arg0;
}
