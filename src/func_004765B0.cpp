typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self, void *sender, s32 msg);
};

struct Owner {
    char pad0[0x5C];
    VEntry *vtbl;
};

struct Obj {
    Owner *owner;
    char pad4[0x3C];
    char sub[1];
};

extern "C" void func_0047CFA0(void *sub);

extern "C" s32 func_004765B0(Obj *self) {
    func_0047CFA0(self->sub);
    Owner *o = self->owner;
    if (o) {
        VEntry *e = &o->vtbl[6];
        return e->fn((char *)o + e->delta, self, 8);
    }
    return 0;
}
