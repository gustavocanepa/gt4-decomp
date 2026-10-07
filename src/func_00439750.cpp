typedef int s32;
typedef short s16;
typedef unsigned char u8;

extern "C" s32 func_005605B0(void *arg0, s32 arg1);

struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *, s32);
};

struct Obj {
    VEntry *vtbl;
    u8 pad4[4];
};

extern "C" void func_00439750(Obj *self, s32 arg1) {
    func_005605B0((void *) &self->pad4, arg1);
    VEntry *entry = self->vtbl + 4;
    s16 delta = entry->delta;
    void (*fn)(void *, s32) = entry->fn;
    fn((void *) ((char *) self + delta), arg1);
}
