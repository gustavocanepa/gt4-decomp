typedef unsigned char u8;

struct Regs {
    char pad[0x2C2];
    u8 value;
};

extern "C" u8 func_004A07F8(void) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    return ptr->value;
}
