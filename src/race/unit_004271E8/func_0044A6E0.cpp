struct Pool {
    int size;
    int count;
    int stride;
    void *mem;
};

extern "C" void *func_00575DC8(int bytes);
extern "C" void func_0044A788(Pool *p);

extern "C" void func_0044A6E0(Pool *p, int size, int count) {
    if (p->mem == 0) {
        int stride = size / 8 * 8 + 0x18;
        p->stride = stride;
        p->mem = func_00575DC8(stride * count);
        p->size = size;
        p->count = count;
    }
    func_0044A788(p);
}
