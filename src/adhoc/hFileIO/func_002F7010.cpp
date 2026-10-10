typedef unsigned int u32;

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
};

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    void terminate() const { dat[length()] = 0; }
    const char *c_str() const {
        if (length() == 0)
            return "";
        terminate();
        return dat;
    }
};

struct Info {
    int w[5];
};

extern "C" Info func_004AE6B0(const char *name);

struct Obj {
    char pad0[0x14];
    String name;
};

extern "C" int func_002F7010(Obj *o) {
    return func_004AE6B0(o->name.c_str()).w[2];
}
