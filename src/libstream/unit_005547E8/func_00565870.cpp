typedef int s32;

struct Slot {
    s32 used;
    char pad[0x1C];
};

struct Obj {
    char pad[8];
    Slot slots[2];
};

extern "C" Slot *func_00565870(Obj *self) {
    s32 i;
    Slot *s = self->slots;
    for (i = 0; i < 2; i++, s++) {
        if (s->used == 0) {
            s->used = 1;
            return s;
        }
    }
    return 0;
}
