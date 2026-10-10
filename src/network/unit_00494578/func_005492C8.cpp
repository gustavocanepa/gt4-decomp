struct Tmp { int w[4]; };
struct Id { unsigned char b[8]; };
extern "C" int func_005488A8(void *);
extern "C" void func_00579BD8(Tmp *, int);
extern "C" Id func_00549398(Tmp *);

extern "C" int func_005492C8(Id *out)
{
    Tmp t;
    func_00579BD8(&t, func_005488A8(out));
    Id r = func_00549398(&t);
    *out = r;
    return 0;
}
