struct Regs { char pad[0x228]; int unk228; };
extern "C" void func_004A3078(int arg0) {
    volatile Regs *p = (volatile Regs *)0x70002000;
    p->unk228 = arg0;
}
