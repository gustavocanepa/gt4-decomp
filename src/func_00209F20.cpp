extern "C" void func_002098B8(void *h);
extern "C" void func_0020A4E0(void *h, int in_chrg);

struct Handle {
    void *p;
    int pad[3];
    Handle() { func_002098B8(this); }
    ~Handle() { func_0020A4E0(this, 2); }
};

struct Ref {
    Ref(const int &v, int flags) __asm__("func_00208EE8");
    Ref(void *p) __asm__("func_0020A8D0");
    ~Ref();
    void *p;
    int pad[3];
};

Ref func_00209F20()
{
    Handle h;
    if (h.p == 0)
        return Ref(0, 0);
    return Ref(h.p);
}
