struct Elem { float v0; float v4; float v8; int pad[5]; };
struct Group { int pad0; Elem *a; Elem *b; int padC; };
struct Entry { int pad0; short x; short y; short z; short padA; int padC; };
struct Data { char pad0[0x10]; Group *groups; char pad14[0x8]; Entry *entries; };
struct Obj { int pad0; Data *data; };

extern "C" int func_0042A220(Obj *o, int idx);

extern "C" float func_0042A100(Obj *o, int idx) {
    int ok = func_0042A220(o, idx);
    float r = 0.0f;
    if (ok) {
        Data *d = o->data;
        Group *g = &d->groups[d->entries[idx].x];
        if (d->entries[idx].y >= 0) {
            Elem *a = &g->a[d->entries[idx].y];
            r = a->v0;
        } else if (d->entries[idx].z >= 0) {
            Elem *b = &g->b[d->entries[idx].z];
            r = b->v8;
        }
    }
    return r;
}
