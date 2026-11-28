/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

/* MGame attribute "entry name": the setter copies the script string into the
 * game data's entry record, the getter returns the record's name as a script
 * string when the record is in use. */

extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
struct TypeName {
    const char *name;
};
extern "C" TypeName *func_005C11A8(void);

/* the game's string: libstdc++ v2 basic_string */
struct Rep {
    s32 len, res, ref, selfish;
    char *data() { return (char *)(this + 1); }
    char *clone() __asm__("func_005C2560");
    char *grab() {
        if (selfish) return clone();
        ++ref;
        return data();
    }
    void release() {
        if (--ref == 0) {
            s32 size = res + 0x10;
            func_00326798(this, size, 4, func_005C11A8()->name);
        }
    }
};
extern Rep D_00659FA8;
extern char D_006901F0[]; /* "" */

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    s32 length() const { return rep()->len; }
    void terminate() const { rep()->data()[length()] = 0; }
    String &replace(s32 pos, s32 n, const char *s, s32 len) __asm__("func_005C2630");
    String(const char *s) : dat(D_00659FA8.grab()) { replace(0, -1, s, func_0057F260(s)); }
    String(const String &);
    ~String() { rep()->release(); }
    const char *c_str() const {
        if (length() == 0) return D_006901F0;
        terminate();
        return rep()->data();
    }
};

struct Object;
extern "C" void func_003285A8(Object *p);
extern "C" void func_003285F8(Object *p);

struct VEntry {
    short delta;
    short index;
    String (*toString)(void *);
};
struct Object {
    s32 refCount;
    VEntry *vtbl;
    String toString() {
        VEntry *e = &vtbl[3];
        return e->toString((char *)this + e->delta);
    }
};

struct Value {
    Object *p;
    Value &operator=(const Value &o) {
        if (this != &o) {
            Object *n = o.p;
            if (n) func_003285A8(n);
            if (p) func_003285F8(p);
            p = n;
        }
        return *this;
    }
};
struct StringValue : Value {
    StringValue(const String &s) __asm__("func_00314B20");
    StringValue(const StringValue &);
    ~StringValue() __asm__("func_00312318");
};

struct Entry {
    char pad0[8];
    char name[0x20];
    char used;
    void setName(const char *s) __asm__("func_0042F860");
    bool isUsed() const { return used; }
    const char *getName() const { return name; }
};
struct GameData {
    char pad0[0x38BF8];
    Entry entry;
};
struct Game {
    char pad0[0x10];
    GameData *data;
};
struct GameRef {
    Game *p;
    GameRef(const GameRef &);
    ~GameRef() __asm__("func_0015F388");
    Game *operator->() const { return p; }
};

GameRef current_game() __asm__("func_0015F3E0");
static inline GameRef game() { return current_game(); }

extern "C" void MGame__get_suspended_racecode(Value *out, void *self, s32 argc, Object **argv) {
    if (argc > 0) {
        game()->data->entry.setName(argv[0]->toString().c_str());
    } else {
        Entry &entry = game()->data->entry;
        if (entry.isUsed())
            *out = StringValue(String(entry.getName()));
    }
}
