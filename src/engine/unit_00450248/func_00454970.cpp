typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad[0x2E];
    u16 size;
    char pad2[0x18];
    void *data;
};

extern "C" void *func_006045A0(void *, void *, s32);

extern "C" void *func_00454970(Obj *self, void *dst) {
    if (self->data == 0)
        return 0;
    return func_006045A0(dst, self->data, self->size);
}
