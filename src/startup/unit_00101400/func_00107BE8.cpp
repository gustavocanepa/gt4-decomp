/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tex { char pad[0x12]; unsigned short size; unsigned short m14; short pad2; int m18; };
struct Buf { void *m0; int m4; int m8; int mC; int m10; };
extern "C" void func_00107B98(Buf *);
extern "C" void func_00107B58(Buf *, int);
extern "C" void func_00498828(Tex *, void *);
extern "C" int func_004A07F8(void);
extern "C" void func_00499508(Tex *);
extern "C" void func_004A2038(int);
extern "C" void func_004A4910(void);
extern "C" void func_00499640(Tex *);

extern "C" void func_00107BE8(Buf *b, Tex *t)
{
    func_00107B98(b);
    func_00107B58(b, t->size << 6);
    func_00498828(t, b->m0);
    if (func_004A07F8()) {
        func_00499508(t);
        func_004A2038(1);
        func_004A4910();
    } else {
        func_00499640(t);
    }
    b->m8 = t->m18;
    b->m10 = 0;
    b->mC = t->m14;
}
