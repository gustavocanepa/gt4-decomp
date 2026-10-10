struct Regs {
    char pad[0x2C8];
    int value;
};

int func_004A7CD0(void) {
    volatile Regs *ptr = (volatile Regs *)0x70002000;
    return ptr->value;
}
