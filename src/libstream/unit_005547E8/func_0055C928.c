/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;

struct Entry {
    int m0;
    int m4;
    int m8;
};

struct Obj {
    char pad0[0x4C];
    struct Entry entries[1];
};

struct Req {
    int m0;
    int pad4[3];
    int index;
    int pad14[7];
    unsigned int flags;
    int pad34[3];
};

extern u64 D_006C8BD0;
extern void func_0055CFE8(struct Req *r, u64 key);
extern void func_0055C9A0(int a, struct Req *r, void (*cb)(void), int b, int c);
extern void func_0055CFA8(void);

void func_0055C928(struct Obj *o, int index, int value, int notify) {
    struct Req r;
    o->entries[index].m0 = value;
    if (notify) {
        func_0055CFE8(&r, D_006C8BD0);
        r.index = index;
        r.flags |= 1;
        func_0055C9A0(r.m0, &r, func_0055CFA8, 0, 0);
    }
}
