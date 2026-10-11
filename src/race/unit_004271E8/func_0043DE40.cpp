struct Data {
    virtual void v0();
    virtual int size();
    virtual void v2();
    virtual void v3();
    virtual int save(void *buf);
    virtual int load(void *buf);
};

extern "C" void *malloc(int size);
extern "C" void free(void *p);

extern "C" void func_0043DE40(Data *dst, Data *src) {
    void *buf = malloc(dst->size());
    src->save(buf);
    dst->load(buf);
    free(buf);
}
