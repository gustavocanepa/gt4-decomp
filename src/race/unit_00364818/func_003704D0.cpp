struct Obj {
    char pad0[0x20];
    float m20;
    float m24;
};

extern "C" float func_00370318(Obj *o, int axis, float cur, float target, float rate);

extern "C" void func_003704D0(Obj *o, float x, float y) {
    float rate = 0x1.999998p-3f;
    o->m20 = func_00370318(o, 1, o->m20, x, rate);
    o->m24 = func_00370318(o, 0, o->m24, y, rate);
}
