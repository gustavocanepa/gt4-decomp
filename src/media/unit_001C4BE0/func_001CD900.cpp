struct Stamp {
    unsigned int a : 9;
    unsigned int b : 6;
    unsigned int c : 8;
    unsigned int x : 1;
    unsigned int d : 1;
    int getA() const { return a; }
    int getB() const { return b; }
    int getC() const { return c; }
    int getD() const { return d; }
};

extern "C" long func_001CD840(void *self);

extern "C" int func_001CD900(void *self, int *pat)
{
    union { long v; Stamp s; } u;
    u.v = func_001CD840(self);
    int r = 0;
    if ((pat[0] < 0 || pat[0] == u.s.getA()) &&
        (pat[1] < 0 || pat[1] == u.s.getB()) &&
        (pat[2] < 0 || pat[2] == u.s.getC()) &&
        (pat[3] < 0 || pat[3] == u.s.getD())) {
        r = 1;
    }
    return r;
}
