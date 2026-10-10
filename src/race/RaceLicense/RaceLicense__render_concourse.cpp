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

extern "C" void GSBuffer__getTexture(void *src, Matrix *out);
extern "C" void Concourse__registerSphereMap(Ghost *g, Matrix *m);
extern "C" void LicenseConcourse__render(Ghost *g, void *value);

extern "C" void RaceLicense__render_concourse(RaceLicense *self, void *src)
{
    Ghost *g = &self->ghost;
    if (g->active) {
        Matrix m;
        GSBuffer__getTexture(src, &m);
        Concourse__registerSphereMap(g, &m);
        LicenseConcourse__render(g, self->world->mid->inner->value);
    }
}
