/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Built without strict aliasing: the load of o.next stays after the store of p in share(). */
typedef int s32;
typedef short s16;

/* a polymorphic game object: the vtable pointer after 0x5C bytes of fields, the destructor first */
struct Obj {
    char pad[0x5C];
    virtual ~Obj();
};

/* a shared pointer whose owners form a ring: the last owner deletes the object */
struct LinkedPtr {
    Obj *p;
    LinkedPtr *prev;
    LinkedPtr *next;
    void release() {
        if (prev == next) {
            if (p) delete p;
        } else {
            next->prev = prev;
            prev->next = next;
        }
    }
    void reset(Obj *q) {
        release();
        p = q;
        next = this;
        prev = this;
    }
    void share(LinkedPtr &o) {
        release();
        p = o.p;
        prev = &o;
        next = o.next;
        o.next = this;
    }
};

struct Entry {
    char pad[0x24];
};

struct Owner {
    char pad0[0x30];
    Entry *entries;
};

struct Self {
    Owner *owner;
    char pad4[0x54];
    s32 unk58;
    char pad5C[0x4];
    s32 unk60;
    char pad64[0x10];
    LinkedPtr second;
    LinkedPtr first;
};

struct Ids {
    s16 v[4];
};

extern "C" Ids *func_00484D20(Self *);
extern "C" void *exception__structor_0(s32);
extern "C" void func_0047FB80(void *, Owner *, Entry *, s32, s32, s32);

extern "C" void func_00484B10(Self *self, s32 arg1) {
    LinkedPtr *h1 = &self->first;
    Ids *ids = func_00484D20(self);
    s32 a = ids->v[3];
    s32 b = ids->v[self->unk60];

    if (h1->p == 0 && a >= 0) {
        Obj *o = (Obj *)exception__structor_0(0xAC);
        func_0047FB80(o, self->owner, &self->owner->entries[a], arg1, 0, self->unk58);
        h1->reset(o);
    }
    if (a == b) {
        self->second.share(*h1);
    } else if (b >= 0) {
        Obj *o = (Obj *)exception__structor_0(0xAC);
        func_0047FB80(o, self->owner, &self->owner->entries[b], arg1, 0, self->unk58);
        self->second.reset(o);
    }
}
