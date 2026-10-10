typedef int s32;
typedef unsigned int u32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);
extern "C" void func_00476768(Val *, const Val *);

struct Entry { const char *name; s32 type; };
extern "C" Entry *func_006061E0(const char *key, Entry *table, s32 count);
extern Entry D_006244F0[];
extern char D_006AD5A8[];

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
    const char *c_str() const { if (length() == 0) return D_006AD5A8; terminate(); return data(); }
};

extern "C" Val *func_00476698(Val *ret, const String &name, char *base) {
    Val tmp;
    Entry *e;
    tmp.type = 1;
    e = func_006061E0(name.c_str(), D_006244F0, 16);
    if (e) {
        s32 type = e->type;
        func_004768C0(&tmp);
        tmp.type = type;
        if (e->type == 9)
            tmp.v = (s32)(base + 0x40);
    } else {
        func_004768C0(&tmp);
    }
    func_00476768(ret, &tmp);
    func_004768C0(&tmp);
    return ret;
}
