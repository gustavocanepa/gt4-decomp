/* compiler: ee-gcc2.96-as2004g */
typedef unsigned char u8;

/* An 8-byte peer address kept unaligned inside the records. */
struct Key8 { unsigned lo, hi; } __attribute__((packed));

struct Entry {
    struct Key8 key;
    int value;
    int kind;
    int x10;
    int x14;
    int x18;
    int x1C;
    int active;
    int x24;
    int notified;
};

struct Obj;

struct Notice {
    struct Obj *self;
    unsigned idx;
    char *name;
    int kind;
    int x80;
    void *user;
};

struct Obj {
    char pad0[0x100];
    struct Entry *spare;
    int id;
    char pad108[0x2C];
    void (*notify)(struct Notice *n);
    void *user;
    char pad13C[8];
    int mode;
    char pad148[4];
    int pending;
    char pad150[8];
    int state;
    u8 flags;
};

struct Hello {
    u8 flags;
    u8 slot;
    char pad2[2];
    struct Key8 key;
    char token[0x40];
};

struct Api {
    char pad0[0x7C];
    void (*format)(char *out, struct Key8 key, struct Entry *e);
};

struct Hooks {
    char pad0[0x30];
    void (*query)(int *out, struct Obj *self);
};

extern struct Api *D_0064B4B0;
extern struct Hooks *D_0064B4B4;

void func_005310D0(struct Obj *self, unsigned idx);
int func_00532588(struct Obj *self, unsigned idx, int type, int size, void *data);
char *func_00535970(unsigned idx);
struct Entry *func_00535C88(struct Obj *self, unsigned idx);
int func_00535CB0(struct Obj *self, unsigned idx, struct Entry **out);
int func_00536568(int id);
int func_00538870(int type, void *out);
void func_0053A878(char *timer);
void *func_005A48D8(void *dst, int c, unsigned n);

/* Handles an accepted join for slot idx (names provisional, inferred from the code): records the
   peer address and value in the slot's entry, and when the spare entry is active in state 4
   announces the slot through the owner's notify callback. In mode 1 (and not state 4) it then
   answers with a 0x4C-byte hello (type 0x10) carrying this host's own slot and address, refreshes
   the slot and, in state 2 when the hook reports this host's id, restarts the peer's timer. */
void func_005319A8(struct Obj *self, unsigned idx, struct Key8 key, int value) {
    struct Hello hello;
    char name[0x10];
    struct Notice notice;
    struct Entry *e = 0;
    int limit = 0x100;

    if (idx >= 0x40)
        return;
    if (self == 0)
        return;
    if (func_00535CB0(self, idx, &e) != 0)
        return;
    if (e == 0)
        return;
    if (e->active) {
        if (self->state != 4)
            func_005310D0(self, idx);
        return;
    }
    if (self->pending)
        self->pending--;
    e->key = key;
    e->value = value;
    e->active = 1;
    e = self->spare;
    if (e == 0)
        return;
    if (e->active && self->state == 4) {
        e = func_00535C88(self, idx);
        if (e == 0)
            return;
        e->kind = 2;
        e->x10 = 0;
        e->x14 = 0;
        e->x1C = 0;
        D_0064B4B0->format(name, e->key, e);
        func_005A48D8(&notice, 0, sizeof(notice));
        notice.name = name;
        notice.kind = e->kind;
        notice.user = self->user;
        notice.self = self;
        notice.idx = idx;
        notice.x80 = 0;
        self->notify(&notice);
        e->notified = 1;
    }
    if (self->mode != 1)
        return;
    if (self->state == 4)
        return;
    hello.slot = func_00536568(self->id);
    e = func_00535C88(self, hello.slot);
    if (e == 0)
        return;
    hello.key = e->key;
    hello.flags = self->flags;
    func_00538870(0, hello.token);
    func_00532588(self, idx, 0x10, 0x4C, &hello);
    func_005310D0(self, idx);
    if (D_0064B4B4)
        D_0064B4B4->query(&limit, self);
    if (self->state != 2)
        return;
    if (self->id != limit)
        return;
    {
        char *peer = func_00535970(idx);
        if (peer == 0)
            return;
        func_0053A878(peer + 0x198);
    }
}
