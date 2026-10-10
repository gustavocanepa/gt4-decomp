/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Inner {
    char pad0[0xB0];
    int mB0;
};

struct Course {
    int m0;
    Inner *inner;
};

struct Obj {
    char pad0[0x80];
    Course *course;
};

struct Src {
    char pad0[0x30];
    float pos;
    int pad34[2];
    int id;
};

struct Out {
    int id;
    int mB0;
    int hit;
    float pos;
};

extern "C" int func_00396098(Course *c, int *buf, int max, int id, float pos, float range);

extern "C" void func_003FDBC8(Obj *o, Src *s, Out *out) {
    int buf[32];
    int id = s->id;
    float pos = s->pos;
    out->mB0 = o->course->inner->mB0;
    out->hit = 0;
    out->pos = 0;
    out->id = id;
    if (func_00396098(o->course, buf, 32, id, pos, 500.0f) > 0) {
        out->hit = buf[0];
        out->pos = pos;
    }
}
