struct C { char pad[0x34]; int f34; };

extern "C" void func_0025BCF0(C *c, int *unk, float *a, float *b, float *d, float *e);

extern "C" void func_0025BAD8(C *c, float fparg0, float fparg1, float fparg2, float fparg3) {
    float sp0 = fparg0;
    float sp4 = fparg1;
    float sp8 = fparg2;
    float spC = fparg3;

    func_0025BCF0(c, &c->f34, &sp0, &sp4, &sp8, &spC);
}
