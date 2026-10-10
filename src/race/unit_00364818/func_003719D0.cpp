struct Vec {
    float x, y, z;
};

struct Obj {
    char pad0[0x34];
    Vec m34;
    char pad40[0x60 - 0x40];
    char m60[0x20];
    int m80;
    char pad84[0xAC - 0x84];
    float mAC;
};

struct Src {
    char pad0[0x34];
    float m34;
};

extern "C" void func_00370DD0(Obj *o, void *m, int a);
extern "C" void func_005F5040(void *m, Vec *v);
extern "C" void func_003704D0(Obj *o, float x, float y);

extern "C" void func_003719D0(Obj *o, Src *s) {
    o->mAC -= s->m34 * 0x1.11111p-4f;
    func_00370DD0(o, o->m60, o->m80);
    func_005F5040(o->m60, &o->m34);
    func_003704D0(o, o->m34.x, o->m34.z);
}
