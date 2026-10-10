typedef unsigned char u8;

struct Ctx {
    char pad0[0x156];
    u8 m156;
};

struct Car {
    char pad0[0x1C0];
    u8 m1C0;
    u8 m1C1;
    u8 m1C2;
    u8 m1C3;
};

struct Rec {
    u8 pad0[3];
    u8 m3;
    u8 m4;
    u8 m5;
    u8 m6;
    u8 m7;
    u8 m8;
};

extern "C" u8 func_004452C0(Ctx *c, int a, int b, int d, int e);
extern "C" void func_003F1748(Car *car);

extern "C" void func_00443040(Ctx *c, Car *car, Rec *r) {
    int lv = c->m156;
    if (lv == 0)
        lv = 1;
    car->m1C2 = r->m5;
    car->m1C0 = r->m3;
    car->m1C1 = r->m4;
    car->m1C3 = func_004452C0(c, r->m7, r->m8, r->m6, lv);
    if (!c->m156)
        func_003F1748(car);
}
