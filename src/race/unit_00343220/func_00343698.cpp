#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct Range;
extern "C" Range D_00620320;
extern "C" float func_00350808(Range *r);

struct Obj {
    char pad[8];
    float value;
    char pad2[8];
    unsigned char locked;
};

extern "C" void func_00343698(Obj *o, float v)
{
    if (!o->locked) {
        if (func_00350808(&D_00620320) < v)
            o->value = func_00350808(&D_00620320);
        else
            o->value = v;
    }
}
