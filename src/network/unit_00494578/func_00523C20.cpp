/* Looks up entry index of the table and resolves its first (which 0) or second (which 1) id:
   through func_00529320 when the id is set, else from the values cached in the entry.
   The resolve step is an inline helper called from both arms: the two copies are merged again
   by cross-jumping, but only after register allocation saw out and extra used twice. */
struct B { char data[8]; };
struct E { int x, first, second; char pad[20]; B value; int extra; char tail[24]; };
struct O { void *handle; char pad[128]; E *entries; char pad2[20]; unsigned short count; };
extern "C" int func_00529320(void *, int, B *, int *);
static inline int fetch(O *self, E *e, int id, B *out, int *extra) {
    if (id != 0) {
        int r = func_00529320(self->handle, id, out, extra);
        if (r != 0) return r;
    } else {
        *out = e->value;
        *extra = e->extra;
    }
    return 0;
}
extern "C" int func_00523C20(O *self, unsigned short index, int which, B *out, int *extra) {
    if (self == 0) return 2;
    if (index >= self->count) return 0xD4E6;
    if (which == 0) {
        E *e = (E *)(index * 68 + (int)self->entries);
        return fetch(self, e, e->first, out, extra);
    } else if (which == 1) {
        E *e = (E *)(index * 68 + (int)self->entries);
        return fetch(self, e, e->second, out, extra);
    }
    return 2;
}
