extern "C" int func_00594470(const char *a, const char *b, unsigned int n);
extern const char D_0069FE40[];

extern "C" int func_0038A468(const char *s)
{
    int r = 0;
    if (func_00594470(s, D_0069FE40, 2) != 0) {
        return 0;
    }
    switch (s[2]) {
    case '4':
        r = 0x10;
        break;
    case '1':
        r = 0x11;
        break;
    case 'm':
        r = 0x12;
        break;
    }
    return r;
}
