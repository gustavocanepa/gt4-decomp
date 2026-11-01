/* Returns 1 when func_003F4EA0 accepts every 0x34-byte item at +0x7B8, for
   as many items as the count byte of the record func_00359510 looks up; 0 on
   the first rejected item. */
struct Info { unsigned char f0; unsigned char count; };
struct Item { char pad[0x34]; };
struct T { char p0[0x10]; int id; char p14[0x7B8 - 0x14]; Item items[1]; };
extern "C" Info *func_00359510(int);
extern "C" int func_003F4EA0(Item *);
extern "C" int func_0035C9E0(T *t) {
    Info *n = func_00359510(t->id);
    int i;
    for (i = 0; i < n->count; i++) {
        if (!func_003F4EA0(&t->items[i])) return 0;
    }
    return 1;
}
