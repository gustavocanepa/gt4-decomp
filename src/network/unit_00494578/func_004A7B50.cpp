typedef int s32;

struct Regs {
    char pad[0xC34];
    s32 value;
};

void func_004A7B50(s32 arg0) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    ptr->value = arg0;
}
