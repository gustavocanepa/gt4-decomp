extern "C" char *func_005A609C(char *dst, const char *src); /* strcpy */
extern "C" char *func_005A6CF8(const char *s, int c);       /* strrchr */
extern const unsigned char D_006D0E79[];                    /* ctype table */
struct Two {
    char c[2];
};

extern const char D_0069DEC8[];                             /* "." */

extern "C" void func_0030D178(char *path, const char *src) {
    func_005A609C(path, src);
    char *p = path;
    if ((D_006D0E79[(int)p[0]] & 3) && p[1] == ':')
        p += 2;
    char *slash = func_005A6CF8(p, '/');
    if (slash != 0) {
        if (slash == p)
            p[1] = 0;
        else
            *slash = 0;
    } else {
        *(Two *)p = *(const Two *)D_0069DEC8;
    }
}
