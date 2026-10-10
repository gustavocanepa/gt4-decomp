typedef int s32;

extern char D_006888E0[];

extern "C" void *func_00470BE8(void *p);
extern "C" void *func_0046F080(void *p);

struct C {
    s32 x0;
    s32 x4;
    s32 x8;
    char a[0x850];
    char b[0x8C];
    void *vtbl;
    C() __asm__("func_0046C050");
};

C::C() {
    vtbl = D_006888E0;
    func_00470BE8(a);
    func_0046F080(b);
    x0 = 0;
    x4 = 0;
    x8 = 0;
}
