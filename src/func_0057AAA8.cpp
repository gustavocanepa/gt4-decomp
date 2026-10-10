typedef unsigned char u8;

struct Obj {
    u8 *id;
};

extern "C" bool func_0057AAA8(Obj *self, const u8 *id) {
    u8 *p = self->id;
    if (!p)
        return 0;
    return p[0] == id[0] && p[1] == id[1] && p[2] == id[2] && p[3] == id[3];
}
