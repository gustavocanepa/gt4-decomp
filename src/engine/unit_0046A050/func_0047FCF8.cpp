struct Obj {
    char pad[0x5C];
    virtual void v0();
    virtual void v1(void *a, int b);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(void *a, int b);
};

extern "C" void func_0047FCF8(Obj *o, void *a) {
    o->v1(a, 0);
    o->v5(a, 10);
}
