typedef int s32;

typedef void (*Fn)(void);
extern Fn D_00651948;
extern "C" void func_005597D8(s32, s32);
extern "C" void func_00568060(s32, void (*)(void), s32);
extern "C" void func_005596D8(void);
extern "C" void func_005596F8(void);

extern "C" void func_00559790(void) {
    func_005597D8(0x3FFF, 0);
    Fn f = func_005596D8;
    D_00651948 = f;
    func_00568060(2, func_005596F8, 0);
}
