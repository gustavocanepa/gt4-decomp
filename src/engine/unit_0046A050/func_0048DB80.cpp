struct M {
    char pad0[0x20];
    float m20;
};

extern "C" void func_0048D740(M *d, int axis, M *a, M *b);

extern "C" void func_0048DB80(M *d, M *a, M *b) {
    func_0048D740(d, 0, a, b);
    func_0048D740(d, 1, a, b);
    d->m20 = a->m20 / b->m20;
}
