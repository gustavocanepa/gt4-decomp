extern "C" char D_0069DA18[];

struct Rep {
    unsigned int len;
    unsigned int res;
    unsigned int ref;
    int selfish;
};
struct Str {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    unsigned int length() const { return rep()->len; }
    const char *c_str() const
    {
        if (length() == 0)
            return D_0069DA18;
        p[length()] = 0;
        return p;
    }
};
extern "C" int func_002FF840(void);
extern "C" void func_005EE900(Str *s, int n, int c);
extern "C" void func_002FF7E8(void *ret, const char *s, int n);

extern "C" void *func_002FFA40(void *ret, Str *s)
{
    int n = func_002FF840();
    func_005EE900(s, n, 0);
    func_002FF7E8(ret, s->c_str(), n);
    return ret;
}
