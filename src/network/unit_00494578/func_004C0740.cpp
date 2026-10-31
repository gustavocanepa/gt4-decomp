/* Reads the big-endian u16 at +0x12 of record idx (20-byte records) found after the header entries
 * of row (id & 0xFF): the row at 0x40 when (id & 0xFF00) == 0x200, else the one at 0x50, and passes
 * it to func_004C0508. The rows go through row(t, offset), a byte offset added to t last as retail does. */
struct Item { char pad[0x12]; unsigned char hi, lo; };
struct Rec { unsigned short v[3]; };
struct Row { Rec *data; int x4; short x8; unsigned short n; unsigned short m; short xE; };
struct Table { char pad[0x40]; Row rows[256]; };
static inline Row *row(Table *t, int off) { return (Row *)((char *)t + off); }
extern "C" int func_004C0508(Table *, unsigned short, unsigned short);
extern "C" int func_004C0740(unsigned short idx, Table *t, unsigned short id) {
    Item *p;
    if ((id & 0xFF00) == 0x200) {
        Row *r = row(t, (id & 0xFF) * 16 + 0x40);
        p = (Item *)&r->data[r->n + 1];
    } else {
        Row *r = row(t, (id & 0xFF) * 16 + 0x50);
        p = (Item *)&r->data[r->n + r->m + 1];
    }
    return func_004C0508(t, id, (p[idx].hi << 8) | p[idx].lo);
}
