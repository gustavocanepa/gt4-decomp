/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val;
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);

/* the script value: type 1 is nil; func_004768C0 releases the payload and sets nil */
struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_00476768(this, &o); }
    ~Val() { func_004768C0(this); }
};

struct Item { u32 flags; short index; short pad; };
struct ItemArray {
    Item *data;
    s32 count;
    Item *begin() const { return data; }
    Item *end() const { return data + count; }
};
struct Def { char pad[0xC]; u32 mask; ItemArray items; };
struct Entry { s32 a, b; };
struct Class { char pad[0xA8]; Entry *entries; };
struct VEntry { short delta; short index; void *(*fn)(void *); };
struct Obj {
    Class *cls;
    Def *def;
    char pad8[0x50];
    s32 f58;
    VEntry *vtbl;
};

static inline void *vcall3(Obj *o) {
    VEntry *e = o->vtbl + 3;
    return e->fn((char *)o + e->delta);
}

extern "C" Val func_004817E8(void *, Entry *, s32);

extern "C" s32 func_0047D968(Obj *self, s32 arg, u32 mask) {
    if (!self->def || !self->f58)
        return 0;
    s32 found = 0;
    if (mask & self->def->mask) {
        for (Item *it = self->def->items.begin(); it != self->def->items.end(); ++it) {
            if (it->flags & mask) {
                func_004817E8(vcall3(self), self->cls->entries + it->index, arg);
                found = 1;
            }
        }
    }
    return found;
}
