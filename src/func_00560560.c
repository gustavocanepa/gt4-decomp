typedef int s32;
typedef unsigned char u8;

extern u8 D_006C8D38[]; /* an empty string: the buffers are set to its first byte */

struct Obj {
    u8 s0[0x40];
    s32 f40;
    u8 s44[0x40];
    u8 s84[0x40];
    u8 sC4[0x40];
    s32 f104;
    u8 s108[0x40];
    u8 s148[0x40];
    s32 f188;
    u8 s18C[0x40];
    s32 f1CC;
    s32 f1D0;
    u8 s1D4[0x40];
    u8 s214[0x40];
    s32 f254;
};

void func_00560560(struct Obj *o) {
    u8 c = D_006C8D38[0];
    o->s0[0] = c;
    o->f40 = 1;
    o->s44[0] = c;
    o->s84[0] = c;
    o->sC4[0] = c;
    o->f104 = 1;
    o->s108[0] = c;
    o->s148[0] = c;
    o->f188 = 0;
    o->s18C[0] = c;
    o->f1CC = 0x50;
    o->f1D0 = 0;
    o->s1D4[0] = c;
    o->s214[0] = c;
    o->f254 = 0;
}
