struct Obj {
    float m0;
    float m4;
    float m8;
};

extern "C" float func_0057AE68(int mode, float t, float range);

extern "C" Obj *func_0057AF68(Obj *o, float t, float scale, float lo, float hi) {
    float d = t - o->m8;
    d = func_0057AE68(1, d - lo, hi - lo) + lo;
    o->m0 += d * scale;
    return o;
}
