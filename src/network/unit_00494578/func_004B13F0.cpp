struct Res {
    int a;
    int b;
    int value;
    int d[5];
};

struct Item {
    char pad[0x48];
    void *lock;
};

struct Param {
    int f0;
    Item *item;
};

struct Out {
    int f0;
    int f4;
    int value;
    char name[4];
};

struct Base {
    char pad[0xA4];
};

class Owner : public Base {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual Res lookup(Item *item);
};

extern "C" const char *func_004AC798(void *lock);
extern "C" void func_004AC7B8(void *lock);
extern "C" void func_005A609C(void *str, const char *s);

extern "C" Out *func_004B13F0(Owner *self, Param *p, Out *out)
{
    Item *item = p->item;
    void *lock = item->lock;
    const char *name = func_004AC798(lock);
    Res r = self->lookup(item);
    out->f4 = 0;
    out->value = r.value;
    func_005A609C(out->name, name);
    func_004AC7B8(lock);
    return out;
}
