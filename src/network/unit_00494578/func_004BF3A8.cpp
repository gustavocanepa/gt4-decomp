/* Stores the 32-bit value at o->src, big-endian, into bytes 0xE..0x11 of record k (20-byte
   records) that follow the header entries of the object's table row: the row at 0x40 for ids of
   kind 0x200, else the one at 0x50. Only slot 0 ids and k in 1..entry count are accepted. */
struct Item { char pad[0xE]; unsigned char b[4]; char pad12[2]; };
struct Rec { unsigned short v[3]; };
struct Row { Rec *data; int x4; short x8; unsigned short n; unsigned short m; short xE; };
struct Table { char pad[0x40]; Row rows[256]; };
struct Obj { char pad[0xC]; unsigned char *src; char pad10[0x14]; Table *table; };
static inline Row *row(Table *t, int off) { return (Row *)((char *)t + off); }
extern "C" int func_004BF3A8(Obj *o, unsigned short id, int index) {
    Table *t;
    unsigned short k;
    Item *p;
    int off;
    if ((id & 0xFF) != 0) return 0x80001E71;
    k = index;
    t = o->table;
    if (k != 0) {
        if ((id & 0xFF00) == 0x200) {
            if (k < row(t, 0x40)->n + 1) goto ok;
        } else {
            Row *r = row(t, 0x50);
            if (k < r->n + r->m + 1) goto ok;
        }
    }
    return 0x80001E71;
ok:
    /* The records start after the row's n (+ m) + 1 header entries; the record offset is added
       to the base before the header size, as the original does. */
    off = k * 20;
    if ((id & 0xFF00) == 0x200) {
        Row *r = row(t, (id & 0xFF) * 16 + 0x40);
        p = (Item *)&((Rec *)((char *)r->data + off))[r->n + 1];
    } else {
        Row *r = row(t, (id & 0xFF) * 16 + 0x50);
        p = (Item *)&((Rec *)((char *)r->data + off))[r->n + r->m + 1];
    }
    p->b[0] = o->src[3];
    p->b[1] = o->src[2];
    p->b[2] = o->src[1];
    p->b[3] = o->src[0];
    return 0;
}
