/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Two-level offset table lookup: entry `a` of the root table locates a
 * sub-table, entry `b` of that sub-table locates the result. Offsets are
 * relative to the root table, bit 0 is a flag, 0xFFFF marks a missing entry. */
typedef unsigned short u16;
struct Table {
    u16 count;
    u16 offsets[1];
};
/* The same 16-bit entry seen as a bit-field: this read is not merged with the
 * plain u16 read of the 0xFFFF test, which is what the original reloads. */
struct EntryBits { unsigned offset : 16; unsigned unused : 16; };
struct Data { char pad0[0x3C]; Table *table; };
struct Obj { char pad0[0x14]; Data *data; };

extern "C" void *func_00559A18(Obj *o, int a, int b) {
    Table *t = o->data->table;
    u16 *offsets;
    u16 *p;
    if (t == 0)
        return 0;
    if (t->count < a)
        return 0;
    offsets = t->offsets;
    p = (u16 *)(a * 2 + (int)offsets);
    if (*p == 0xFFFF)
        return 0;
    p = (u16 *)((char *)t + (((EntryBits *)p)->offset & 0xFFFE));
    if (((Table *)p)->count < b)
        return 0;
    return (char *)t + (*(((Table *)p)->offsets + b) & 0xFFFE);
}
