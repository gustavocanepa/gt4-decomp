struct Limits;

extern Limits D_00620320;

extern "C" float func_003507A8(Limits *l);

struct Obj {
    char pad0[4];
    float value;
    char pad[12];
    unsigned char locked;
};

extern "C" void func_00343578(Obj *o, float v) {
    if (o->locked)
        return;
    Limits *l = &D_00620320;
    if (func_003507A8(l) < v)
        o->value = func_003507A8(l);
    else
        o->value = v;
}
