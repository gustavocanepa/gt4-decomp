struct Ctx { int handle; int pad[3]; };
struct Str { int p; int pad[3]; int get() const { return p; } };
extern "C" void func_002E3BC0(Ctx *c);
extern "C" void func_002E3B68(Ctx *c, int flags);
extern "C" void func_002434C8(Str *s, const char *text);
extern "C" void func_00243470(Str *s, int flags);
extern "C" void func_002E4358(int handle, int str);

extern "C" void MTextActor__global_0083B7C8(void *self, void *unused, int argc, const char *arg)
{
    if (argc > 0) {
        Ctx c;
        func_002E3BC0(&c);
        Str s;
        func_002434C8(&s, arg);
        func_002E4358(c.handle, s.get());
        func_00243470(&s, 2);
        func_002E3B68(&c, 2);
    }
}
