typedef int s32;

struct Obj {
    char pad[0x7C];
    s32 count;
};

extern "C" void func_00393B00(Obj *);

static inline s32 bump(s32 *p) {
    return (*p)++;
}

extern "C" void func_00393B30(Obj *self) {
    if (self->count != 0) {
        if (bump(&self->count) >= 2)
            func_00393B00(self);
    }
}
