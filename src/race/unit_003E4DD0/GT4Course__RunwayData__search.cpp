struct Vec3 { float x, y, z; };

struct Box {
    Vec3 min;
    Vec3 max;
};


struct Obj {
    char pad[0x20];
    Box box;
    char pad38[0x14];
    unsigned short count;
};

extern "C" int GT4Course__RunwayData__traverse(Obj *o, void *arg, Box *box, const Vec3 *from, const Vec3 *to, int a, int last, int b);

extern "C" int GT4Course__RunwayData__search(Obj *o, void *arg, const Vec3 *p) {
    if (p->y < o->box.min.y)
        return 0;
    Vec3 from;
    Vec3 to;
    from.x = p->x;
    from.y = o->box.max.y < p->y ? o->box.max.y : p->y;
    from.z = p->z;
    to.x = p->x;
    to.y = o->box.min.y;
    to.z = p->z;
    return GT4Course__RunwayData__traverse(o, arg, &o->box, &from, &to, 0, o->count - 1, 0);
}
