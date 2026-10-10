extern int D_0086F7C0;
extern int D_0086F7C4;
extern int D_0086F7C8;
extern int D_0086F7CC;
extern int D_0086F7D0;
extern int D_0086F7D4;
extern int D_0086F7D8;
extern int D_0086F7DC;

extern "C" void func_0054FB38(int xbits, int ybits) {
    D_0086F7C0 = xbits;
    D_0086F7CC = ybits;
    D_0086F7C4 = 1 << xbits;
    D_0086F7C8 = (1 << xbits) - 1;
    D_0086F7D0 = 1 << ybits;
    D_0086F7D4 = (1 << ybits) - 1;
    D_0086F7D8 = 1 << (ybits + xbits);
    D_0086F7DC = (1 << (ybits + xbits)) - 1;
}
