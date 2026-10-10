typedef int s32;

struct Sem { char b[0xC0]; };
extern Sem D_0086F640[2];
extern "C" void func_00578148(Sem *, s32);

extern "C" void func_0054F340(void) {
    func_00578148(&D_0086F640[0], 0x4D504731);
    func_00578148(&D_0086F640[1], 0x4D504732);
}
