/* compiler: ee-gcc2.96-no-strict-aliasing */
unsigned int func_0057F260(const char *s);
char *func_00577BD0(char *dst, const char *src);
int func_005B6C68(const char *path, int mode, int arg);
void func_00577F80(void);

int func_00577518(const char *path, int mode, int arg) {
    char *buf = __builtin_alloca(func_0057F260(path) + 1);
    int r;
    func_00577BD0(buf, path);
    while ((r = func_005B6C68(buf, mode, arg)) < 0)
        func_00577F80();
    return r;
}
