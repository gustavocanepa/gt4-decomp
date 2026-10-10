struct Limits;

extern Limits D_00620B00;

extern "C" float func_003662F8(Limits *l);

struct Obj {
    char pad0[16];
    float value;
    unsigned char locked;
};

extern "C" void func_00343978(Obj *o, float v) {
    if (o->locked)
        return;
    Limits *l = &D_00620B00;
    if (func_003662F8(l) < v)
        o->value = func_003662F8(l);
    else
        o->value = v;
}
