extern char D_006C3390[];
extern int func_005A609C(char *, char *);
int func_0052E4E0(char *buf) {
    int r = 0x17;
    if (buf != 0) {
        func_005A609C(buf, D_006C3390);
        r = 0;
    }
    return r;
}
