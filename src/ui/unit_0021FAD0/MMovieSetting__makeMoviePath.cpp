struct Str8 { char c[8]; };
extern char *D_006190C8;
extern const Str8 D_00698028;
extern const char D_00698030[];
extern const char D_00698040[];
extern char D_0082D790[];
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_00329F50(char *, int, const char *);
extern "C" int func_0057DA20(char *, const char *, ...);

extern "C" char *MMovieSetting__makeMoviePath(void)
{
    char *path = D_006190C8;
    if (!path) {
        char buf[0x40];
        *(Str8 *)buf = D_00698028;
        func_005A48D8(buf + 8, 0, 0x38);
        func_00329F50(buf, 0x40, D_00698030);
        func_0057DA20(D_0082D790, D_00698040, buf);
        D_006190C8 = D_0082D790;
        path = D_0082D790;
    }
    return path;
}
