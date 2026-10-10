struct Name { const char *str; int pad[3]; };

extern "C" void func_002FC8C8(Name *self, const char *s);
extern "C" void func_002FC870(Name *self, int flags);
extern "C" int func_002FE250(const char *s);
extern "C" void func_001FE4E8(void *target, int on);
extern "C" char D_00618E40[];

extern "C" void MMovieFace__setPause(void *self, int argc, const char *arg)
{
    int on = 1;
    if (argc > 0) {
        Name n;
        func_002FC8C8(&n, arg);
        on = func_002FE250(n.str) != 0;
        func_002FC870(&n, 2);
    }
    func_001FE4E8(D_00618E40, on);
}
