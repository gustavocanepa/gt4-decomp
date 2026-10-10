struct Data {
    virtual void v0();
    virtual int size();
    virtual void v2();
    virtual void v3();
    virtual int save(void *buf);
    virtual int load(void *buf);
};

extern "C" void *func_00575DC8(int size);
extern "C" void func_00575DA0(void *p);

extern "C" void func_0043DE40(Data *dst, Data *src) {
    void *buf = func_00575DC8(dst->size());
    src->save(buf);
    dst->load(buf);
    func_00575DA0(buf);
}
