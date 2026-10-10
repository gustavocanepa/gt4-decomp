/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Medius: the name of a game entry (or "" when the lookup fails), returned as a basic_string<char>
 * (gcc 2.96 bastring.h members inline: grab, the (const char *) constructor, assign). */
typedef unsigned int u32;

struct Heap { const char *name; };

extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, int size, int align, const char *name);
extern "C" u32 func_0057F260(const char *s);

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char &operator[](u32 s) { return data()[s]; }
    inline char *grab();
    static void operator delete(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep) + res);
    }
};

extern "C" char *func_005C2560(Rep *r);
extern Rep D_00659FA8;

inline char *Rep::grab() {
    if (selfish)
        return func_005C2560(this);
    ++ref;
    return data();
}

struct String;
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String {
    char *dat;
    char pad[0xC];
    Rep *rep() const { return (Rep *)dat - 1; }
    String() : dat(D_00659FA8.grab()) {}
    ~String() { rep()->release(); }
    String(const char *s) : dat(D_00659FA8.grab()) { assign(s); }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
};

extern char D_00645570[];
extern int func_004F3C00(void *, int);
extern char *func_004F3EF8(void *, int);
extern void mUpdateContext__Sync(int);
extern int func_001F1368(void *);

String func_001F60A0(void *ctx, int id)
{
    while (!func_004F3C00(D_00645570, id))
        mUpdateContext__Sync(1);
    if (!func_001F1368(ctx) || *(int *)(*(char **)(D_00645570 + 0x5A8) + 0x5B30) == 0) {
        return String();
    }
    return String(func_004F3EF8(D_00645570, 0) + 0x4C);
}
