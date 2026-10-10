typedef int s32;

struct Id { char b[8]; };
extern struct Id D_00655880;

struct Obj {
    struct Id id;
    struct Id a;
    struct Id b;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
};

void func_00577240(struct Obj *o, s32 x, const struct Id *id) {
    o->id = *id;
    o->a = D_00655880;
    o->b = D_00655880;
    o->f18 = x;
    o->f1C = 0;
    o->f20 = 0;
    o->f24 = 1;
}
