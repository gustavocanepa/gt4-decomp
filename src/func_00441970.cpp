typedef unsigned char u8;

struct Rec {
    u8 m0, m1, m2, m3, m4, m5, m6, m7, m8, m9;
};

struct Obj {
    char pad[0x12F];
    u8 m12F;
    u8 m130;
};

struct Out {
    char pad[0x1A8];
    u8 m1A8;
    u8 m1A9;
};

extern "C" u8 func_004452C0(Obj *o, int a, int b, int c, int d);

extern "C" void func_00441970(Obj *o, Out *out, Rec *r) {
    out->m1A8 = func_004452C0(o, r->m4, r->m5, r->m3, o->m12F);
    out->m1A9 = func_004452C0(o, r->m8, r->m9, r->m7, o->m130);
}
