struct Manager {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int acquire(int id);
    virtual void release(int id);
};

struct Handle {
    Manager *mgr;
    int id;
    int data;
};

extern "C" void func_004B23F0(Handle *h, int id) {
    if (h->id != -1) {
        h->mgr->release(h->id);
        h->data = 0;
        h->id = -1;
    }
    h->data = h->mgr->acquire(id);
    if (h->data)
        h->id = id;
}
