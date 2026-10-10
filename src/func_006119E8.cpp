struct Timer { char pad[0x4C]; float total; };
extern "C" unsigned long long func_0055A810(Timer *t);

extern "C" void func_006119E8(Timer *t)
{
    t->total += func_0055A810(t);
}
