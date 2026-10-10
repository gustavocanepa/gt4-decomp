struct Obj_003A5C68 {
    char pad0[0x10];
    void *m10;
    char pad14[4];
    void *m18;
    void *m1C;
};

extern "C" void *func_003A1E10(const char *name);
extern "C" char D_006A1490[];
extern "C" char D_006A14A0[];
extern "C" char D_006A14B0[];

extern "C" void func_003A5C68(Obj_003A5C68 *o) {
    if (o->m10 == 0) {
        o->m10 = func_003A1E10(D_006A1490);
        o->m18 = func_003A1E10(D_006A14A0);
        o->m1C = func_003A1E10(D_006A14B0);
    }
}
