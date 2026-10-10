struct func_004C2758_Out {
    int flags;
    signed char b4;
    unsigned char kind;
    short h6;
};

extern "C" int func_004C9580(int a, int b);

extern "C" int func_004C2758(int kind, int on, int a, func_004C2758_Out *out) {
    int b;
    short v;
    switch (kind) {
    case 0: case 1: case 2:
        b = 8;
        v = -100;
        break;
    case 20:
        b = 10;
        v = 0;
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16:
        b = 1;
        v = 0;
        break;
    case 17:
        b = 8;
        v = 0;
        break;
    case 18:
        b = 0x12B;
        v = 0;
        break;
    default:
        return 0;
    }
    if (func_004C9580(a, b) != 1)
        return 0;
    out->flags = 0x100000;
    if (on)
        out->h6 = v;
    else
        out->h6 = 0;
    out->b4 = on;
    out->kind = kind;
    return 1;
}
