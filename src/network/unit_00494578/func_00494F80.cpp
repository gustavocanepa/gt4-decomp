struct Stream {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    char pad18[0x20];
    int f38;
    int f3C;
    int f40;
};

extern "C" int func_00494FC8(Stream *s);

extern "C" int func_00494F80(Stream *s, int a, int b) {
    s->f0 = b;
    s->f4 = a;
    s->f8 = -1;
    s->f38 = 1;
    s->fC = 0;
    s->f10 = 0;
    s->f14 = 0;
    s->f3C = 0;
    s->f40 = 0;
    return func_00494FC8(s);
}
