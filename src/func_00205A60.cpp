struct Ctx { int handle; int pad[3]; };
struct Str { int p; int pad[3]; int get() const { return p; } };
extern "C" void func_00204D88(Ctx *c);
extern "C" void func_00204D30(Ctx *c, int flags);
extern "C" void func_00255110(Str *s, const char *text);
extern "C" void func_002550B8(Str *s, int flags);
extern "C" void func_00206EC0(int handle, int str);

extern "C" void func_00205A60(void *self, void *unused, int argc, const char *arg)
{
    if (argc > 0) {
        Ctx c;
        func_00204D88(&c);
        Str s;
        func_00255110(&s, arg);
        func_00206EC0(c.handle, s.get());
        func_002550B8(&s, 2);
        func_00204D30(&c, 2);
    }
}
