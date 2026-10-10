struct Obj {
    char pad[0x9290];
    void *items[0xFD];
    int states[8];
};

extern "C" int func_003CC7B0(Obj *o, int i);
extern "C" int func_003D2788(Obj *o, int i);

extern "C" int func_003D28A0(Obj *o, int i) {
    int r = func_003CC7B0(o, i);
    if (r == 0)
        return r;
    if (o->states[i] == 5 && o->items[i] && !func_003D2788(o, i))
        return 1;
    return 0;
}
