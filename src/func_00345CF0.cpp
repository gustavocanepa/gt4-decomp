struct BitReader;
extern "C" long func_0057AD58(BitReader *r, int bits);
extern int D_00620218[];

extern "C" int func_00345CF0(BitReader *r) {
    int n = func_0057AD58(r, 3);
    int neg = func_0057AD58(r, 1);
    int v = func_0057AD58(r, n * 2 + 1) + D_00620218[n];
    return neg ? -v : v;
}
