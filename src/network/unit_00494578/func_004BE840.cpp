/* Removes an entry by key: key 0x2FFFFF clears the whole slot through func_004BD230; otherwise it looks
 * the key up (func_004BC978, func_004BE698), decrements the row count at +8 and returns the record's
 * two size bytes through out. Rows are reached with row(t, offset) as in func_004C0740. */
struct Row { void *data; int x4; unsigned short x8; };
struct Table;
struct Msg { unsigned short key; char pad2[0xC]; unsigned char a, b; char pad10[0x10]; };
struct Obj { int x0; int *state; char pad8[0x1C]; Table *table; };
static inline Row *row(Table *t, int off) { return (Row *)((char *)t + off); }
extern "C" void func_004BEC88(Obj *, int);
extern "C" void func_004BD230(Obj *, unsigned short);
extern "C" int func_004BC978(Table *, unsigned short, Msg *, int);
extern "C" int func_004BE698(Obj *, Msg *, unsigned short) throw();
extern "C" int func_004BE980(Obj *, unsigned short);
extern "C" int func_004BE840(Obj *o, unsigned short id, unsigned int key, int *out) {
    Msg msg;
    if (*o->state == 0)
        func_004BEC88(o, 1);
    if (key == 0x2FFFFF) {
        func_004BD230(o, id);
    } else {
        msg.key = key;
        if ((unsigned short)key == 0)
            return 0x80001E6D;
        if (func_004BC978(o->table, id, &msg, 0) <= 0 || func_004BE698(o, &msg, id) < 0)
            return 0x80001E6D;
        if ((id & 0xFF00) == 0x200)
            row(o->table, (id & 0xFF) * 16 + 0x40)->x8--;
        else
            row(o->table, (id & 0xFF) * 16 + 0x50)->x8--;
        *out = msg.a + msg.b;
    }
    if ((id & 0xFF00) == 0x200)
        return func_004BE980(o, id);
    return 0;
}
