typedef unsigned char u8;

struct Obj {
    u8 pad[0x30];
    u8 unk30;
};

extern char D_00620478[];

extern "C" void *func_00359510(Obj *arg0) {
    return D_00620478 + arg0->unk30 * 0x54;
}
