struct Obj { char pad[0x17C]; int key; };
struct Handle;
extern "C" {
void func_0013BDC0(Handle *h, void *src);
void func_0013BD68(Handle *h, int flags);
}
struct Handle {
    Obj *p;
    int pad[3];
    Handle(void *x) { func_0013BDC0(this, x); }
    ~Handle() { func_0013BD68(this, 2); }
    Obj *operator->() { return p; }
};

extern "C" int func_00146A20(void *x, void *y)
{
    Handle a(x);
    int ka = a->key;
    Handle b(y);
    return ka < b->key;
}
