struct Scale { int m0, m4; };
extern Scale D_00623838;
extern "C" void func_004AA168(unsigned int);
extern "C" void func_004A1638(int);
extern "C" void func_004AB040(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004A4550(int, int);
extern "C" void func_0044DBC0(Scale *, float, float);

extern "C" void func_003AECE0(void)
{
    func_004AA168(0x80FFFFFF);
    func_004A1638(6);
    func_004AB040(8);
    func_004AB040(5);
    func_004AB040(4);
    func_004AB040(3);
    func_004A2808(0x44, 0.0f);
    func_004A4550(2, 1);
    func_004A4550(3, 1);
    Scale *s = &D_00623838;
    s->m4 = 0;
    func_0044DBC0(s, 1.0f, 1.0f);
}
