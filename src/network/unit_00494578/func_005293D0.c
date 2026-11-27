/* compiler: ee-gcc2.96-as2004g */
typedef unsigned short u16;

/* An 8-byte peer address kept unaligned inside the records. */
struct Key8 { unsigned lo, hi; } __attribute__((packed));
struct Key16 { int w[2]; };
struct Words { int w[2]; };

struct Api {
    char pad0[0x6C];
    void (*make)(struct Key16 *key);
    char pad70[4];
    int (*same)(struct Key16 a, struct Key8 b);
};

struct Registry {
    char pad0[0x18];
    void (*bind)(int which, int handle, char *name);
    void (*name)(int which, int id, char *out);
    char pad20[0xC];
    void (*add)(int which, int handle, char *name);
    char pad30[0x24];
    void (*init)(char *name);
};

struct Info {
    struct Key8 key;
    int id;
    int option;
    u16 port;
    void (*onEvent)(int);
    int (*onData)(void *);
    void *user;
};

struct Conn {
    int state;
    int pad4;
    struct Key8 key;
    int id;
    char buf14[0x18];
    char buf2C[0x18];
    char timer44[8];
    char timer4C[8];
    char pad54[0x10];
    int retries;
    int retryMs;
    u16 port;
    u16 localPort;
    char pad70[4];
    u16 seq;
    char pad76[0xA];
    int option;
    int handle;
    char pad88[4];
    int (*onData)(void *);
    void (*onEvent)(int);
    u16 pending;
    char pad96[0x402];
    void *user;
};

struct Owner {
    char pad0[0x50];
    int id;
    int size54;
    int size58;
};

extern struct Api *D_0064B4B0;
extern struct Registry *D_0064B710;

int func_005288E8(void);
unsigned func_00528940(unsigned n);
int func_00529228(struct Owner *self, struct Key16 *key, int *out);
int func_005292C0(struct Owner *self, struct Key16 *key, int *out);
struct Conn *func_0052AA18(struct Owner *self);
int func_0052BDD8(struct Owner *self, struct Conn *c);
int func_0052D448(char *buf, unsigned size);
/* Declared int on purpose: the call then sets $v0 instead of clobbering it, which
   decides the sched2 order of the stores after it. The callee itself is a void
   tail-call wrapper. */
int func_0053A860(char *timer);

/* Opens a connection record for the peer described by info: rejects a peer whose id and address
   are this host's own (two lookups), allocates the record, its two buffers and random port/sequence
   numbers, copies the peer description, registers the name when the registry is active and starts
   the handshake. Names are provisional, inferred from the code. Returns 0, 2 for bad arguments,
   0xD2F2 for a null owner, 0xD305 for a connection to itself, 0xD2F7 when out of resources. */
int func_005293D0(struct Owner *self, struct Info *info, struct Conn **out) {
    struct Key16 key;
    char name[0x40];
    char entry[0x40];
    int idx;
    struct Conn *c;

    if (out == 0)
        return 2;
    *out = 0;
    if (self == 0)
        return 0xD2F2;
    if (info->onEvent == 0)
        return 2;
    if (info->onData == 0)
        return 2;

    D_0064B4B0->make(&key);
    idx = 0;
    func_00529228(self, &key, &idx);
    if (info->id == idx) {
        if (D_0064B4B0->same(key, info->key))
            return 0xD305;
    }
    D_0064B4B0->make(&key);
    idx = 0;
    func_005292C0(self, &key, &idx);
    if (info->id == idx) {
        if (D_0064B4B0->same(key, info->key))
            return 0xD305;
    }

    c = func_0052AA18(self);
    if (c == 0)
        return 0xD2F7;
    *out = c;
    c->pending = 0;
    if (func_0052D448(c->buf14, self->size54) == 0 && func_0052D448(c->buf2C, self->size58) == 0) {
        c->state = 10;
        c->seq = func_00528940(0xFFFF);
        c->localPort = func_00528940(0x3FF);
        {
            int id = info->id;
            void *user = info->user;
            u16 port = info->port;
            c->id = id;
            c->key = info->key;
            c->onEvent = info->onEvent;
            c->user = user;
            c->onData = info->onData;
            c->port = port;
        }
        func_0053A860(c->timer44);
        func_0053A860(c->timer4C);
        c->retryMs = 1000;
        c->retries = 0;
        c->option = info->option;
        if (func_005288E8() == 1) {
            D_0064B710->init(entry);
            D_0064B710->add(-1, c->handle, entry);
            D_0064B710->name(-1, self->id, name);
            D_0064B710->bind(-1, c->handle, name);
        }
        if (func_0052BDD8(self, c) == 0)
            return 0;
    }
    c->state = 7;
    return 0xD2F7;
}
