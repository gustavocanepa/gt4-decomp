typedef unsigned char u8;

struct Obj {
    u8 pad[0x30];
    u8 unk30;
};

struct Arg {
    unsigned char pad0[0x10];
    Obj *unk10;
};

extern char D_00620478[];

extern "C" void *func_00359538(Arg *arg0) {
    return D_00620478 + arg0->unk10->unk30 * 0x54;
}
