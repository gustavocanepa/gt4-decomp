struct Iter { int w[4]; };
struct Info { int count; };
extern "C" Info *func_0046A050(void *, int);
extern "C" void func_00469F08(Iter *, void *, int);
extern "C" char *func_00469FC8(Iter *, int);
extern "C" void *func_005A48D8(void *, int, unsigned int);

extern "C" int func_0046B9F0(void *t)
{
    if (!func_0046A050(t, 5)) return 0;
    Iter it;
    func_00469F08(&it, t, 5);
    for (int i = 0; i < func_0046A050(t, 5)->count; i++)
        func_005A48D8(func_00469FC8(&it, i) + 0x38, 0, 8);
    return 1;
}
