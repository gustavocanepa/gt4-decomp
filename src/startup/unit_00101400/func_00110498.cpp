extern char *D_00622F4C;
extern const char D_0068D2C8[], D_0068D2D0[], D_0068D2D8[], D_0068D2E0[], D_0068D2E8[];

struct func_00110498_Obj {
    char pad[0x45];
    unsigned char kind;
};

extern "C" int func_004312B0(void *db, const char *name);

extern "C" int func_00110498(func_00110498_Obj *self) {
    unsigned char kind = self->kind;
    if (kind == 0)
        return 1;
    int r = 0;
    switch (kind) {
    case 1:
        r = func_004312B0(D_00622F4C + 0x13E28, D_0068D2C8);
        break;
    case 2:
        r = func_004312B0(D_00622F4C + 0x13E28, D_0068D2D0);
        break;
    case 3:
        r = func_004312B0(D_00622F4C + 0x13E28, D_0068D2D8);
        break;
    case 4:
        r = func_004312B0(D_00622F4C + 0x13E28, D_0068D2E0);
        break;
    case 5:
        r = func_004312B0(D_00622F4C + 0x13E28, D_0068D2E8);
        break;
    }
    return r;
}
