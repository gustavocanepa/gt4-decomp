extern const char D_0068D1F0[], D_0068D200[], D_0068D210[], D_0068D220[], D_0068D230[], D_0068D240[],
    D_0068D250[];

extern "C" {
int func_0038A3B8(const char *code);
int func_0038A3D0(const char *code);
char *func_005A6AB0(char *dst, const char *src, int n);
int func_0057DA20(char *out, const char *fmt, ...);
int func_0057F260(const char *s);
}

/* QUICK_MENU::GetNextLicenseCode (GT HD name): the code of the license test after `code`. */
extern "C" int QUICK_MENU__GetNextLicenseCode(const char *code, char *out) {
    char head[16];
    char body[16];
    int type = func_0038A3B8(code);
    int n = func_0038A3D0(code);
    func_005A6AB0(head, code, 2);
    if (type == 8) {
        func_0057DA20(out, D_0068D1F0, head, n - 3);
        return 1;
    }
    if (n == 9) {
        switch (type) {
        case 1:
        default:
            func_0057DA20(out, D_0068D200, head);
            break;
        case 2:
            func_0057DA20(out, D_0068D210, head);
            break;
        case 3:
            func_0057DA20(out, D_0068D220, head);
            break;
        case 4:
            func_0057DA20(out, D_0068D230, head);
            break;
        case 5:
            func_0057DA20(out, D_0068D240, head);
            break;
        }
        return 1;
    }
    type++;
    if (type >= 17)
        return 0;
    func_005A6AB0(body, code, func_0057F260(code) - 4);
    func_0057DA20(out, D_0068D250, body, type);
    return 1;
}
