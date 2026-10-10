/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Val { s32 type; s32 v; };
extern "C" void func_004768C0(Val *);

struct String3;
extern "C" void func_00605A98(String3 *str, u32 len, s32 force);
extern "C" String3 *func_00605888(String3 *str, u32 pos, u32 n1, u32 n2, char c);

struct String3 {
    struct Rep {
        u32 len, res, ref, selfish;
        char *data() { return (char *)(this + 1); }
        char &operator[](u32 s) { return data()[s]; }
    };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    void alloc(u32 size, s32 save) { func_00605A98(this, size, save); }
    void unique() { if (rep()->ref > 1) alloc(length(), 1); }
    void selfish() { unique(); rep()->selfish = 1; }
    char &operator[](u32 pos) { selfish(); return (*rep())[pos]; }
    char *ibegin() const { return &(*rep())[0]; }
    char *begin() { selfish(); return &(*this)[0]; }
    char *end() { selfish(); return &(*this)[length()]; }
    String3 &replace(u32 pos, u32 n1, u32 n2, char c) { return *func_00605888(this, pos, n1, n2, c); }
    char *erase(char *f, char *l) {
        u32 o = f - ibegin();
        replace(o, l - f, (u32)0, (char)0);
        selfish();
        return ibegin() + o;
    }
    void clear() { erase(begin(), end()); }
};

struct Obj {
    char pad[0x16C];
    s32 f16C;
    s32 f170;
    Val val;
    String3 str;
};

extern "C" void func_00475F38(Obj *self) {
    self->f16C = 0;
    self->str.clear();
    func_004768C0(&self->val);
}
