struct Obj {
    char pad0[0xEC];
    int index;
};

extern "C" int func_0057F238(const char *a, const char *b);
extern const char *D_00618A70[];

extern "C" void func_00192EA8(Obj *o, const char *name) {
    for (int i = 0; i < 9; i++) {
        if (func_0057F238(name, D_00618A70[i]) == 0) {
            o->index = i;
            return;
        }
    }
    o->index = 0;
}
