struct Vec3 {
    float x, y, z;
};

struct Obj {
    char pad[0x18];
    Vec3 a;
    Vec3 b;
};

struct Entry {
    char data[0x20];
};

extern Entry D_006A3AB0[];

extern "C" void func_003E8438(void *self, Obj *o, Entry *e, void *p, void *q, int n);

extern "C" void func_003E8728(void *self, Obj *o, void *p, int idx) {
    float ax = o->a.x, ay = o->a.y, az = o->a.z;
    float bx = o->b.x, by = o->b.y, bz = o->b.z;
    o->a.x = bx;
    o->a.y = by;
    o->a.z = bz;
    o->b.x = ax;
    o->b.y = ay;
    o->b.z = az;
    func_003E8438(self, o, &D_006A3AB0[idx], p, p, 4);
}
