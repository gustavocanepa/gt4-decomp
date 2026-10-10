struct Obj {
    int m0;
    int mode;
    char pad8[8];
    float scale;
    char pad14[0x18];
    void *src;
};

extern "C" float func_0025B370(void *p);
extern "C" float func_0025B3D0(void *p);

extern "C" float func_002D2218(Obj *o) {
    if (o->src == 0)
        return o->scale;
    float v;
    if (o->mode)
        v = func_0025B370(o->src);
    else
        v = func_0025B3D0(o->src);
    return v / o->scale;
}
