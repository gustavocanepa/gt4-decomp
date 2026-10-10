struct Regs {
    char pad[0x1F8];
    int value;
};

int func_004A1A88(void) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    return ptr->value;
}
