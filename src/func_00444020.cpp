struct Obj {
    char pad0[0x4];
    int index;
};

extern "C" int func_0057F238(const char *a, const char *b);
extern const char *D_00623580[];

extern "C" void func_00444020(Obj *o, const char *name) {
    for (int i = 0; i < 9; i++) {
        if (func_0057F238(name, D_00623580[i]) == 0) {
            o->index = i;
            return;
        }
    }
    o->index = 0;
}
