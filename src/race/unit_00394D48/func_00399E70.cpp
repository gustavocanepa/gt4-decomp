struct Ctx { int m0, m4, m8; };
extern "C" void func_001056A0(Ctx *);
extern "C" void func_004AB040(int);
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" int func_00105818(Ctx *);
extern "C" void func_004A6290(int, int, int, int);

extern "C" void func_00399E70(void *self, Ctx *c)
{
    func_001056A0(c);
    func_004AB040(5);
    func_004A1638(6);
    func_004A2808(0xA4, 1.0f);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
    int m8 = c->m8;
    func_004A6290(0, 0, m8, func_00105818(c));
}
