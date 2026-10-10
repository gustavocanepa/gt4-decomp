typedef unsigned int u32;

extern const char D_00697EE8[]; /* "" */

struct StringRep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
};

/* gcc 2.96 bastring.h basic_string<char> (length, empty, c_str with terminate). */
struct String {
    char *dat;
    StringRep *rep() const { return (StringRep *)dat - 1; }
    u32 length() const { return rep()->len; }
    u32 size() const { return rep()->len; }
    bool empty() const { return size() == 0; }
    const char *data() const { return rep()->data(); }
    void terminate() const { (*rep())[length()] = 0; }
    /* c_str() without its empty check (the caller tests empty() first; bastring's own c_str()
       keeps a second length test, the original has none). */
    const char *terminated() const
    {
        terminate();
        return data();
    }
    const char *c_str() const
    {
        if (length() == 0)
            return D_00697EE8;
        terminate();
        return data();
    }
};

struct Entry {
    char data[0x34];
};

struct Owner {
    char pad0[0x60];
    Entry *entries;
};

struct Ref {
    short pad0[3];
    short index;
};

struct Label {
    Owner *owner;
    Ref *ref;
    char pad8[0x4C];
    String name;
    char pad58[8];
    String text;
};

extern "C" void func_00479CA0(Entry *e, void *arg, const char *text, bool unnamed);

extern "C" void func_00479520(Label *l, void *arg)
{
    if (!l->text.empty()) {
        Entry *e = &l->owner->entries[l->ref->index];
        func_00479CA0(e, arg, l->text.terminated(), l->name.empty());
    }
}
