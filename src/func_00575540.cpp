/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Res {
    int refs;
};

struct Slot {
    int key;
    struct Res *res;
};

struct Table {
    char pad0[0x4C];
    struct Slot *slots;
    int pad50;
    int count;
    Slot *at(int i) { return &slots[i]; }
};

extern "C" void func_00576788(struct Table *t);
extern "C" void func_005767C0(struct Table *t);
extern "C" int func_00575620(struct Table *t, int key);

extern "C" void func_00575540(struct Table *t, int key) {
    int i;
    func_00576788(t);
    i = func_00575620(t, key);
    if (i >= 0) {
        struct Res *r = t->at(i)->res;
        int n = r->refs;
        if (n & 1) {
            r->refs = n - 1;
            t->count--;
        }
    }
    func_005767C0(t);
}
