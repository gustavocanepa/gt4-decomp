/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char CarGeometry__vtable[];
extern char MTRGeometry__vtable[];
extern char SpecialCarGeometry__vtable[];
extern char NormalCarGeometry__vtable[];

struct SubA {
    void *vtbl;
    int m4;
    void init() { vtbl = MTRGeometry__vtable; m4 = 0; }
};

struct SubB {
    void *vtbl;
    int m4;
    int m8;
    void init() { vtbl = NormalCarGeometry__vtable; m8 = 0; }
};

struct Geo {
    void *vtbl;
    SubA a;
    void *vtblC;
    SubB b;
    int m1C;
};

extern "C" void func_0038DC30(Geo *self, int a, int b, int c);

extern "C" void CarGeometry__structor_0(Geo *self, int a, int c) {
    self->vtbl = CarGeometry__vtable;
    self->a.init();
    self->vtblC = SpecialCarGeometry__vtable;
    self->b.init();
    self->m1C = 0;
    return func_0038DC30(self, a, 0, c);
}
