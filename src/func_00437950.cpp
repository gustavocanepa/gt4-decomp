extern const char D_0068BB20[], D_006A5DD0[];
extern "C" unsigned int func_00552640(void);
extern "C" int func_0057F238(const char *, const char *);

extern "C" int func_00437950(void) {
    switch (func_00552640()) {
    case 0:
        return 0;
    case 1:
        return (func_0057F238(D_0068BB20, D_006A5DD0) == 0) ? 2 : 1;
    case 2:
        return 3;
    case 3:
        return 6;
    case 4:
        return 4;
    case 5:
        return 5;
    case 7:
        return 7;
    default:
        return 2;
    }
}
