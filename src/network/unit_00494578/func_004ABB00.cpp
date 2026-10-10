struct Obj {
    char pad0[9];
    unsigned char wide;
    char padA;
    unsigned char enabled;
    char padC[8];
    int value;
    char pad18[0x2B0];
    unsigned int mode;
    int alt;
};

extern "C" void func_004ABB00(Obj *o) {
    int v = 0x367;
    if (o->wide)
        v = 0x385;
    if (o->enabled) {
        switch (o->mode) {
        case 1:
            v += o->alt == 0 ? 0x14 : 0xA;
            break;
        case 2:
            v += o->alt == 0 ? 0xA : 0x14;
            break;
        case 3:
            v = 0;
            break;
        }
    }
    o->value = v;
}
