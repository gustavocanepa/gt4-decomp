struct Seq {
    char pad[0x58];
    unsigned char *pc;
};

extern "C" long long D_006C8BD0;
extern "C" void func_00611AA0(Seq *s, int c, int a, int b);
extern "C" void func_0055AA28(Seq *s, long long d, int c, int a, int flag);

extern "C" void func_0055AED8(Seq *s)
{
    int a = *s->pc++;
    int b = *s->pc++;
    int c = *s->pc++;
    if (b)
        return func_00611AA0(s, c, a, b);
    func_0055AA28(s, D_006C8BD0, c, a, 1);
}
