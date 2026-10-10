struct Inner {
    char pad[0x90];
    float scale[4];
    char padA0[0x20];
    int ids[4];
};

struct Obj {
    union {
        struct {
            char pad[0x80];
            float value[4];
            char pad90[0x20];
            int current[4];
        } a;
        struct {
            char pad[8];
            Inner in;
        } b;
    };
};

extern "C" void *func_003CC8B0(void *p);
extern "C" void func_00429AD8(void *ctx, int src, int id, float *out);

extern "C" void func_003CBA88(Obj *o, int i, void *p, int id) {
    float t = 0.0f;
    if (id >= 0)
        func_00429AD8(func_003CC8B0(p), o->b.in.ids[i], id, &t);
    o->a.current[i] = id;
    o->a.value[i] = t;
    o->b.in.scale[i] = 1.0f;
}
