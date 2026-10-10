typedef unsigned short u16;

struct Owner {
    char pad0[0xF4];
    char sound[4];
};

struct Obj {
    Owner *owner;
    char pad4[0xCBF4 - 4];
    u16 timer;
};

extern "C" void func_003B76F0(void *sound, int a, int b, int c);

extern "C" void func_0034C0E0(Obj *self) {
    if (self->timer) {
        if (--self->timer == 0)
            func_003B76F0(self->owner->sound, 1, 0, 0);
    }
}
