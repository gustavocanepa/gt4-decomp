struct Sub { int w; };
struct Item { char pad[0x54]; Sub sub; };
extern "C" char D_006A1458[];
extern "C" void func_003A4CF0(Item *self, const char *name, float x, float y);
extern "C" void func_003A4E00(Item *self, float a, float b);
extern "C" void func_003A99A8(Sub *s);

extern "C" void func_003A4DA0(Item *self)
{
    func_003A4CF0(self, D_006A1458, 0.0f, 0.0f);
    func_003A4E00(self, -1.0f, 0.0f);
    func_003A99A8(&self->sub);
}
