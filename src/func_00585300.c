struct Slot {
    int f0, f4, f8;
    int id;
    char pad[0x48 - 0x10];
};

struct Pool {
    char pad0[0x24];
    struct Slot *slots;
    int count;
};

extern struct Pool D_00875898;

struct Slot *func_00585300(void) {
    int i;
    struct Slot *s = D_00875898.slots;
    for (i = 0; i < D_00875898.count; i++, s++) {
        if (s->id == 0) {
            s->id = -1;
            return s;
        }
    }
    return 0;
}
