struct Slot { char pad0[8]; short id; char padA[6]; bool used() const { return id >= 0; } };
struct Table { char pad0[0x16]; unsigned short count; char pad18[4]; Slot *slots; };
extern "C" int func_004298E0(Table *t, int n) {
    for (int i = 0; i < t->count; i++) {
        if (t->slots[i].used()) {
            if (--n < 0) {
                return i;
            }
        }
    }
    return -1;
}
