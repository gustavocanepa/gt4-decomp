typedef unsigned int u32;

struct StringRep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
};

extern const char D_00690F78[]; /* "" */

/* gcc 2.96 bastring.h basic_string<char>: c_str() terminates the data unless it is empty. */
struct String {
    char *dat;
    StringRep *rep() const { return (StringRep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { (*rep())[length()] = 0; }
    const char *c_str() const
    {
        if (length() == 0)
            return D_00690F78;
        terminate();
        return data();
    }
};

struct Handle {
    void *p;
    int pad[3];
};

extern "C" void func_00312370(Handle *h, void *arg);
extern "C" void func_00312318(Handle *h, int in_chrg);
extern "C" String *func_00314920(void *p);
struct Obj {
    void *p;
    int pad[3];
    void *get() const { return p; }
};

extern "C" void func_001792D8(Obj *o, void *arg);
extern "C" void func_00179280(Obj *o, int in_chrg);
extern "C" void func_0017C9E8(void *p, const char *s);

extern "C" void MMemoryCardManager__test(void *self, void *key, int count, void *arg)
{
    if (count > 0) {
        Handle h;
        func_00312370(&h, arg);
        Obj o;
        func_001792D8(&o, key);
        void *p = o.get();
        func_0017C9E8(p, func_00314920(h.p)->c_str());
        func_00179280(&o, 2);
        func_00312318(&h, 2);
    }
}
