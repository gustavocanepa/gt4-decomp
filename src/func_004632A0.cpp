struct Entry { char d[0x24]; };
struct Out { int a, b, c, d; };
extern "C" unsigned int func_00463278(void *p);
extern "C" int func_00462998(Entry *e);
extern Entry D_008485C0[];

extern "C" void func_004632A0(void *p, Out *out)
{
    unsigned int v = func_00463278(p);
    out->a = func_00462998(&D_008485C0[v >> 24]);
    out->b = (v >> 16) & 0xFF;
    out->c = (v >> 8) & 0xFF;
    out->d = v & 0xFF;
}
