typedef int s32;

struct Rep {
    s32 len;
    s32 res;
    s32 ref;
    s32 sel;
};

extern char D_0068FD90[];

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    s32 length() const { return rep()->len; }
    const char *c_str() const { if (length() == 0) {
            return D_0068FD90;
        }
        dat[length()] = 0;
        return dat; }
};

extern "C" void func_001561F0(void *self, const char *s);

extern "C" void mCarModelPS2__virtual_50(void *self, const String *s) {
    func_001561F0(self, s->c_str());
}
