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
    char pad0[0x34];
    float pos;
    int pad38;
    int id;
};

struct Out {
    int id;
    int mB0;
    int hit;
    float pos;
};

extern "C" int func_00396078(Course *c, int *buf, int max, int id, float pos);

extern "C" void func_003FD980(Obj *o, Src *s, Out *out) {
    int buf[32];
    int id = s->id;
    float pos = s->pos;
    out->mB0 = o->course->inner->mB0;
    out->hit = 0;
    out->pos = 0;
    out->id = id;
    if (func_00396078(o->course, buf, 32, id, pos) > 0) {
        out->hit = buf[0];
        out->pos = pos;
    }
}
