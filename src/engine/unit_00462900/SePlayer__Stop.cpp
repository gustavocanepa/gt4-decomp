struct Child {
    char pad[0x64];
    virtual void v00(); virtual void v01();
    virtual void release(int how);
};

struct Obj {
    int m0;
    int owned;
    char pad[0xC];
    Child *child;
    void *buffer;
};

extern "C" void func_0055A258(void *p);

extern "C" void SePlayer__Stop(Obj *o, int how)
{
    if (o->owned == 0) {
        if (o->buffer) {
            func_0055A258(o->buffer);
            o->buffer = 0;
        }
    } else if (o->child) {
        o->child->release(how);
        o->child = 0;
    }
}
