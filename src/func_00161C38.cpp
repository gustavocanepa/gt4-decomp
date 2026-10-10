extern "C" void func_0015F3E0(void *a);
extern "C" void func_0015F388(void *a, int in_chrg);
extern "C" void *func_0017FB28(void *b, void *name);
extern "C" void func_0017FAD0(void *b, int in_chrg);
extern "C" void func_0043A970(void *dst, void *src);
extern "C" void func_004365B8(void *obj);

struct Node {
    char pad0[0x10];
    void *obj;
};

struct Handle {
    Node *p;
    int pad[3];
    void *get() { return p->obj; }
};

extern "C" void func_00161C38(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        Handle a;
        Handle b;
        func_0015F3E0(&a);
        func_0017FB28(&b, name);
        func_0043A970(a.get(), b.get());
        func_004365B8(b.get());
        func_0017FAD0(&b, 2);
        func_0015F388(&a, 2);
    }
}
