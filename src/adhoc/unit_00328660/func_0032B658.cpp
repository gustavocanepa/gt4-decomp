typedef unsigned int u32;

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
};

struct String;
extern "C" String *func_005CE388(String *str, u32 pos1, u32 n1, const String *s, u32 pos2, u32 n2);

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    String &replace(u32 pos1, u32 n1, const String &str, u32 pos2, u32 n2) {
        return *func_005CE388(this, pos1, n1, &str, pos2, n2);
    }
    String &append(const String &str, u32 pos = 0, u32 n = (u32)-1) { return replace(length(), 0, str, pos, n); }
};

extern "C" String *func_0032B658(String *self, const String *str) {
    self->append(*str);
    return self;
}
