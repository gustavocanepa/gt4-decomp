/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob {
    long long id;
    void *data;
    int size;
};

extern "C" void func_0044A2A8(Blob *b);
extern "C" void *func_00575DC8(int size);
extern "C" void *func_005A4724(void *dst, const void *src, int n);

extern "C" void func_00449EF0(Blob *b, const Blob *o)
{
    func_0044A2A8(b);
    b->id = o->id;
    if (o->data) {
        b->data = func_00575DC8(o->size);
        func_005A4724(b->data, o->data, o->size);
        b->size = o->size;
    }
}
