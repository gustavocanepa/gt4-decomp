struct Reader {
    int m0, m4, m8;
    int mode;
    unsigned char *p;
    int avail;
    int m18;
    int m1C;
    int eof;
};
extern "C" void func_0046E8E0(Reader *);

extern "C" int func_0046E978(Reader *r)
{
    if (r->eof) return 0;
    if (r->mode != 7) {
        func_0046E8E0(r);
        r->mode = 7;
    }
    if (!r->avail) {
        r->m1C = 1;
        r->eof = 1;
        return 0;
    }
    int c = *r->p;
    func_0046E8E0(r);
    r->m18 = 1;
    return c;
}
