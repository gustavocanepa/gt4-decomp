struct Entry { char data[0x20]; };

struct Obj {
    int f0;
    int f4;
    Entry entries[2];
};

extern "C" void func_005A48D8(void *p, int c, int n);

extern "C" void func_005658B0(Obj *o, Entry *e) {
    int i;
    for (i = 0; i < 2; i++) {
        if (&o->entries[i] == e) {
            func_005A48D8(&o->entries[i], 0, sizeof(Entry));
            return;
        }
    }
}
