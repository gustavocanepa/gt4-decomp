struct Obj {
    int m0;
    int mode;
    char pad8[8];
    float scale;
    char pad14[0x18];
    void *src;
};

extern "C" float mWidget__getWindowW(void *p);
extern "C" float mWidget__getWindowH(void *p);

extern "C" float func_002D2218(Obj *o) {
    if (o->src == 0)
        return o->scale;
    float v;
    if (o->mode)
        v = mWidget__getWindowW(o->src);
    else
        v = mWidget__getWindowH(o->src);
    return v / o->scale;
}
