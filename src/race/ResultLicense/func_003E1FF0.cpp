struct Obj {
    int f0;
    int f4;
    void setA(int a) __asm__("func_001053F8");
    void setSize(int w, int h) __asm__("func_00105460");
    void setB(int b) __asm__("func_001054A0");
};

extern "C" void func_004A7CA0(int *a, int *b, int *w, int *h);

extern "C" void func_003E1FF0(void *self, Obj *o) {
    int a, b, w, h;
    func_004A7CA0(&a, &b, &w, &h);
    o->setA(a);
    o->f4 = b;
    o->setSize(w, h);
    o->setB(0);
}
