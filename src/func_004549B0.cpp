typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad0[0x26];
    u16 size;
    char pad28[0x28];
    void *data;
};

extern "C" void *func_00604620(void *dst, const void *src, u16 n);

extern "C" void *func_004549B0(Obj *self, void *dst) {
    if (self->data == 0) {
        return 0;
    }
    return func_00604620(dst, self->data, self->size);
}
