/* compiler: ee-gcc2.96-as2004 */
/* Creates a connection entry from a config (names provisional, inferred from the code): takes a free
   table slot, copies the config, starts one or two sockets depending on the type, then finishes
   through func_0051D448. Returns 0 from there, 2 for bad arguments, 3 or 0xCB20 for a bad state, or
   the first error. The types matter to the scheduler: enum fields and the called functions' int
   returns decide which loads and stores may be reordered, and which registers stay free. */
struct Addr { int a, b; } __attribute__((packed));
struct Stamp { int a, b; };
enum Kind { KIND_0, KIND_1 };
struct Config {
    enum Kind type;
    struct Addr addr;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    unsigned int f24;
    unsigned int f28;
    void *data;
    unsigned int size;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
};
enum Mode { MODE_0, MODE_1 };
struct Options { enum Mode a; int b, c; };
struct Slot {
    char pad0[4];
    int f4;
    int f8;
    char padC[4];
    struct Addr addr;
    void *f18;
    char f1C[4];
    char f20[8];
    char f28[8];
    int f30;
    char f34[8];
    int f3C;
    int f40;
    int f44;
    char pad48[12];
    char f54[24];
    char f6C[32];
    int f8C;
    int f90;
};
struct Entry {
    int f0;
    unsigned int f4;
    int f8;
    char fC[0x2C];
    void *f38;
    unsigned int f3C;
    char pad40[0x24];
    char f64[0x14];
    struct Slot *slots[2];
    struct Slot *f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
};
struct Ops {
    char pad0[0x14];
    int (*f14)(void *, struct Stamp, int, struct Options *);
    char pad18[0x54];
    void (*f6C)(struct Stamp *);
};
struct Hooks {
    char pad0[0x14];
    int (*f14)(int, int, int);
    char pad18[0x44];
    int (*f5C)(int);
};
extern struct Ops *D_0064B4B0;
extern struct Hooks *D_0064B710;
extern unsigned int D_0064AE10;
extern int func_0051D920(int *out, enum Kind type, unsigned int a, unsigned int b);
extern struct Entry *func_0051DD50(int index);
extern int func_005A4724(void *dst, const void *src, unsigned int n);
extern int func_00538BF8(void *out, unsigned long long size);
extern int func_0053A860(void *p);
extern int func_005380B8(void *p);
extern int func_005A48D8(void *p, int c, unsigned int n);
extern int func_0051D448(struct Entry *e);

int func_0051CD28(int *out, struct Config *cfg)
{
    struct Options options;
    struct Stamp stamp;
    int index = 0;
    struct Entry *entry;
    struct Slot **cursor;
    struct Slot *slot;
    unsigned int i;
    int status;

    if (cfg->f0C == 0) {
        return 2;
    }
    if (cfg->f38 == 0) {
        return 2;
    }
    if (cfg->type >= 2) {
        return 2;
    }
    D_0064B4B0->f6C(&stamp);
    *out = D_0064AE10 + 1;
    status = func_0051D920(&index, cfg->type, cfg->f24, cfg->f28);
    if (status != 0) {
        return status;
    }
    *out = index;
    if (D_0064B710 != 0) {
        D_0064B710->f5C(index & 0x7FFFFFFF);
        D_0064B710->f14(index & 0x7FFFFFFF, 0, cfg->f18);
    }
    entry = func_0051DD50(index);
    entry->f8 = 0;
    func_005A4724(entry->fC, cfg, 0x4C);
    if (cfg->data != 0 && cfg->size != 0) {
        status = func_00538BF8(&entry->f38, cfg->size);
        if (status != 0) {
            return status;
        }
        func_005A4724(entry->f38, cfg->data, cfg->size);
        entry->f3C = cfg->size;
    } else {
        entry->f38 = 0;
        entry->f3C = 0;
    }
    D_0064B4B0->f6C((struct Stamp *)entry->f64);
    {
        int v38 = cfg->f38;
        int v40 = cfg->f40;
        int v3C = cfg->f3C;
        int v44 = cfg->f44;
        int v48 = cfg->f48;
        int v34 = cfg->f34;
        entry->f88 = v38;
        entry->f8C = v40;
        entry->f90 = v3C;
        entry->f94 = v44;
        entry->f98 = v48;
        entry->f84 = v34;
    }
    i = 0;
    cursor = entry->slots;
    for (; i < 2; i++) {
        slot = *cursor++;
        if (slot != 0) {
            slot->f8C = 0;
            slot->f90 = 0;
            func_0053A860(slot->f20);
            func_0053A860(slot->f28);
            slot->f30 = cfg->f1C;
            slot->f3C = 0;
            func_0053A860(slot->f34);
            slot->f40 = cfg->f20;
            slot->f44 = 0;
            func_005380B8(slot->f54);
            func_005380B8(slot->f6C);
        }
    }
    entry->f8 = 2;
    if (entry->f4 == 1) {
        slot = entry->slots[1];
        if (slot == 0) {
            return 3;
        }
        func_005A48D8(&options, 0, 12);
        options.b = 0x248;
        options.a = MODE_1;
        status = D_0064B4B0->f14(slot->f1C, stamp, cfg->f14, &options);
        if (status != 0) {
            return status;
        }
        slot->f4 = 0;
    }
    if (entry->f4 < 2) {
        slot = entry->slots[0];
        if (slot == 0) {
            return 3;
        }
        slot->addr = cfg->addr;
        slot->f18 = (void *)cfg->f0C;
        func_005A48D8(&options, 0, 12);
        options.c = 1;
        options.a = MODE_0;
        status = D_0064B4B0->f14(slot->f1C, *(struct Stamp *)&cfg->addr, (int)cfg->f0C, &options);
        if (status != 0) {
            return status;
        }
        slot->f4 = 1;
        entry->f80 = slot;
    }
    if (entry->f80 == 0) {
        return 3;
    }
    if (entry->f0 != entry->f80->f8) {
        return 0xCB20;
    }
    return func_0051D448(entry);
}
