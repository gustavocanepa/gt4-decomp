typedef int s32;
typedef unsigned int u32;
extern char D_0069E1B0[];
#define EMPTY D_0069E1B0

struct String {
    struct Rep { u32 len, res, ref, selfish; char *data() { return (char *)(this + 1); } };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    const char *data() const { return dat; }
    void terminate() const { rep()->data()[length()] = 0; }
};

static inline const char *c_str(const String &s) {
    if (s.length() == 0)
        return EMPTY;
    s.terminate();
    return s.data();
}

struct Obj { char pad[0x10]; String name; };
extern "C" s32 func_005A2F70(const char *);
extern "C" void func_0057FA48(s32);

extern "C" void func_00314A88(Obj *o) {
    func_0057FA48(func_005A2F70(c_str(o->name)));
}
