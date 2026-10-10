typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad0[0x48];
    u16 flags;
    char pad4A[0x2E];
    char name[0x40];
};

extern "C" char *func_005A6AB0(char *dst, const char *src, s32 n);

extern "C" s32 func_001CF278(Obj *self, const char *name) {
    char *d = self->name;
    if ((u16)(self->flags & 1) == 0) {
        return 0;
    }
    d[0x3F] = 0;
    func_005A6AB0(d, name, 0x3F);
    return 1;
}
