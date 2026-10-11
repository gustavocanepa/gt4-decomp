/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob {
    long long id;
    void *data;
    int size;
};

extern "C" void func_0044A2A8(Blob *b);
extern "C" void *malloc(int size);
extern "C" void *memcpy(void *dst, const void *src, int n);

extern "C" void func_00449EF0(Blob *b, const Blob *o)
{
    func_0044A2A8(b);
    b->id = o->id;
    if (o->data) {
        b->data = malloc(o->size);
        memcpy(b->data, o->data, o->size);
        b->size = o->size;
    }
}
