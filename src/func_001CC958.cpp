extern char D_00618D18[];
extern char D_0068BAF8[];
extern char D_0068BB10[];
extern "C" char *func_005A609C(char *, const char *);
extern "C" char *func_005A5DC8(char *, const char *);

extern "C" char *func_001CC958(void) {
    char *buf = D_00618D18;
    if (buf[0] == 0) {
        func_005A609C(buf, D_0068BAF8);
        func_005A5DC8(buf, D_0068BB10);
    }
    return buf;
}
