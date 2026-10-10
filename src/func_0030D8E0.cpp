typedef int s32;

struct Str { char *p; };
extern char D_0069DED8[];
extern "C" void func_0030C548(const char *);

extern "C" void func_0030D8E0(Str *s) {
    char *d = s->p;
    s32 n = ((s32 *)d)[-4];
    const char *c;
    if (n == 0) {
        c = D_0069DED8;
    } else {
        d[n] = 0;
        c = s->p;
    }
    func_0030C548(c);
}
