/* Releases a slot by id: re-looks the entry up after notifying its owner, sets the slot's flag
   (cleared when the id lies outside the owner's range), frees the entry and empties its cell.
   The flag pointer is computed inside the second lookup's test: that gives it the base's register. */
struct Obj { char pad0[8]; int key; char padc[0x10]; void *x1C; void *x20; char pad24[0x14]; void *x38; void *x3C; };
struct Range { char pad[8]; int start; int len; };
struct G { char pad0[0x118]; void *mgr; char pad11c[0xA51C]; int table[0x1000]; unsigned char flags[0x1000]; };
extern struct G D_00854038;
struct Obj *func_00515DD8(int);
void func_005160C0(int, int);
struct Range *func_0051B8A8(void *, int);
void func_00531738(void *);

int func_00516130(int id) {
    struct Obj *p;
    void *mgr = D_00854038.mgr;
    unsigned char *flag;
    struct Range *q;
    if (mgr == 0)
        return 8;
    p = func_00515DD8(id);
    if (p == 0)
        return 8;
    func_005160C0(p->key, id);
    if ((p = func_00515DD8(id)) != 0) {
        flag = 0xE638 + (unsigned char *)(id + (int)&D_00854038);
        *flag = 1;
        q = func_0051B8A8(mgr, p->key);
        if (q != 0) {
            if (id < q->start || !(id < q->start + q->len))
                *flag = 0;
        }
        func_00531738(&p->x20);
        func_00531738(&p->x1C);
        func_00531738(&p->x38);
        func_00531738(&p->x3C);
        D_00854038.table[id] = 0;
        func_00531738(&p);
    }
    return 0;
}
