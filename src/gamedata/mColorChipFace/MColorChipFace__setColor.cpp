extern "C" void func_00157D68(void *);
extern "C" void func_00157D10(void *, int);
extern "C" void func_002ED618(void *, void *);
extern "C" void func_002ED5C0(void *, int);

struct Target;

extern "C" void func_001588C8(Target *t, void *b);

struct A {
    Target *p;
    int pad[7];
};

struct B {
    int v[4];
};

extern "C" void MColorChipFace__setColor(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_00157D68(&a);
        Target *t = a.p;
        func_002ED618(&b, name);
        func_001588C8(t, &b);
        func_002ED5C0(&b, 2);
        func_00157D10(&a, 2);
    }
}
