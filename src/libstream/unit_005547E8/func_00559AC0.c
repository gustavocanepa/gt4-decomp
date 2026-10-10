typedef unsigned int u32;
typedef unsigned short u16;

struct Res { char pad[0x44]; u16 *table; };
struct Obj { char pad[0x14]; struct Res *res; };

void *func_00559AC0(struct Obj *o, u32 idx) {
    u16 *t = o->res->table;
    u16 off;
    if (!t || ((u32)t & 1))
        return 0;
    if (t[0] < idx)
        return 0;
    off = t[idx + 1];
    if (off == 0xFFFF)
        return 0;
    return (char *)t + off;
}
