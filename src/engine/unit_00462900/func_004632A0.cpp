struct Entry { char d[0x24]; };
struct Out { int a, b, c, d; };
extern "C" unsigned int getNumber(void *p);
extern "C" int GTSOUNDINSTRUMENTJAM__getJam(Entry *e);
extern Entry D_008485C0[];

extern "C" void func_004632A0(void *p, Out *out)
{
    unsigned int v = getNumber(p);
    out->a = GTSOUNDINSTRUMENTJAM__getJam(&D_008485C0[v >> 24]);
    out->b = (v >> 16) & 0xFF;
    out->c = (v >> 8) & 0xFF;
    out->d = v & 0xFF;
}
