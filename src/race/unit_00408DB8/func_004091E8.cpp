/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Query {
    float value;
    int m4;
    int m8;
    int mC;
    int mode;
    int flags;
};

struct Owner {
    int m0;
    int m4;
    void *target;
};

struct Obj {
    int m0;
    Owner *owner;
    char pad8[0x38];
    void *src;
    int m44;
    float value;
};

extern "C" int LicenseConcourse__isCameraPeriod(Obj *o);
extern "C" Query *func_00427800(Query *q, float a, void *src, float b);
extern "C" void func_00429BC0(void *target, Query *q);

extern "C" void func_004091E8(Obj *o, float x) {
    if (!LicenseConcourse__isCameraPeriod(o))
        return;
    Query q;
    func_00427800(&q, o->value, o->src, x);
    q.mode = 1;
    q.flags = 0;
    func_00429BC0(o->owner->target, &q);
    o->value = q.value;
}
