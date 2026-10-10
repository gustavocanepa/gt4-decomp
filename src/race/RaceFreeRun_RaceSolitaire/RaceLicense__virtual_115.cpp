struct Matrix {
    float m[12];
};

struct Inner {
    char pad0[0x80];
    void *value;
};

struct Mid {
    int pad0;
    Inner *inner;
};

struct Outer {
    char pad0[0x80];
    Mid *mid;
};

struct Ghost {
    int active;
};

struct RaceLicense {
    char pad0[0x6C];
    Outer *world;
    char pad70[0x24E5C - 0x70];
    Ghost ghost;
};

extern "C" void func_00105930(void *src, Matrix *out);
extern "C" void func_00408470(Ghost *g, Matrix *m);
extern "C" void func_004096C0(Ghost *g, void *value);

extern "C" void RaceLicense__virtual_115(RaceLicense *self, void *src)
{
    Ghost *g = &self->ghost;
    if (g->active) {
        Matrix m;
        func_00105930(src, &m);
        func_00408470(g, &m);
        func_004096C0(g, self->world->mid->inner->value);
    }
}
