/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val;
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);

/* the script value: type 1 is nil, 6 a float; func_004768C0 releases the payload and sets nil */
struct Val {
    s32 type;
    union {
        s32 v;
        f32 f;
    };
    Val() : type(1) {}
    Val(f32 x) : type(6) { f = x; }
    Val(const Val &o) { func_00476768(this, &o); }
    ~Val() { func_004768C0(this); }
};

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
};
extern char D_006ADD60[];
#define EMPTY D_006ADD60

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return EMPTY;
    s.terminate();
    return s.data();
}
extern char D_006ADD68[];

struct Entry { const char *name; Val (*fn)(void *self, s32 z, s32 c); };
extern Entry D_00624818[];
extern "C" Entry *func_006072E0(const char *key, Entry *table, s32 count);
extern "C" void func_00476A08(Val *);
extern "C" void func_0057D9C0(const char *, ...);

extern "C" Val func_0047CE40(Val * self, const String &name, s32 c, s32 z) {
    Entry *e = func_006072E0(c_str(name), D_00624818, 1);
    if (e)
        return e->fn(self, z, c);
    Val t;
    func_00476A08(&t);
    func_0057D9C0(D_006ADD68, c_str(name));
    return t;
}
