struct Shape;
struct Query {
    float a[3];
    float b[3];
};

struct Obj {
    int unk0;
    Shape *shape;
};

extern "C" float func_00395DE8(Shape *s, Query *q);
extern "C" float func_00395EF0(Shape *s, Query *q);
extern "C" float func_00395E18(Shape *s, Query *q, float *b);

extern "C" float func_00396138(Obj *o, int kind, Query *q) {
    switch (kind) {
    case 0:
        return func_00395DE8(o->shape, q);
    case 1:
        return func_00395EF0(o->shape, q);
    case 2:
        return func_00395E18(o->shape, q, q->b);
    }
    return 0.0f;
}
