typedef unsigned long u64;
typedef unsigned int u32;
typedef int s32;

struct Request {
    s32 a;
    /* a union member: its stores alias every other access, which keeps retail's store order */
    union {
        s32 size;
        u32 capacity;
    };
    s32 c;
};

struct Conn {
    s32 handle;
    s32 sock;
    s32 flags;
    char pad0C[0x2030 - 0xC];
    s32 active;
    s32 f2034;
    char pad2038[0x2044 - 0x2038];
    s32 f2044;
    char pad2048[0x207C - 0x2048];
    char line[0x800];
    char host[0x400];
    char agent[0x200];
};

struct Iface {
    char pad00[0x14];
    s32 (*open)(struct Conn *, u64, s32, struct Request *);
    void (*close)(s32);
    s32 (*write)(s32, char *, s32, s32 *);
    char pad20[0x6C - 0x20];
    void (*key)(u64 *);
    char pad70[0x78 - 0x70];
    void (*format)(char *, u64);
};

struct Self {
    char pad00[0x44];
    struct Conn *conn;
    s32 f48;
};

extern "C" {
extern struct Iface *D_0064B4B0;
extern s32 D_0086B540[];
extern char D_006C3EF8[];
extern char D_006C3F08[];
extern char D_006C3F20[];
s32 func_0053BC28(s32 *, s32, char *);
s32 func_0053B6E8(char *, char *, u64 *, s32 *);
s32 func_00540BF8(s32 *, s32, s32);
char *func_005A6AB0(char *, const char *, s32);
void *func_005A48D8(void *, s32, s32);
s32 func_0057F260(const char *);
s32 func_0057DA20(char *, const char *, ...);
void func_00540EB0(s32);
s32 func_0053C2F0(struct Self *self, char *path, char *host);
}

s32 func_0053C2F0(struct Self *self, char *path, char *host) {
    struct Request req;
    u64 key;
    char name[16];
    s32 port;
    s32 written;
    s32 r;
    struct Conn *conn;

    D_0064B4B0->key(&key);
    conn = self->conn;
    conn->active = 1;
    conn->f2034 = 0;
    conn->f2044 = 0;
    r = func_0053BC28(D_0086B540, conn->flags, conn->line);
    if (r != 0) {
        return r;
    }
    r = func_0053B6E8(self->conn->line, self->conn->host, &key, &port);
    if (r != 0) {
        return r;
    }
    if (!(self->conn->flags & D_0086B540[0])) {
        return 0xD6DD;
    }
    if (self->conn->flags != 0x1000 && !(self->conn->flags & 0x800)) {
        return 2;
    }
    r = func_00540BF8(&self->conn->sock, 0xB, self->f48);
    if (r != 0) {
        return r;
    }
    if (self->conn->sock == 0) {
        return r;
    }
    if (self->conn->flags == 0x1000) {
        func_005A6AB0(self->conn->agent, D_006C3EF8, 0x200);
    } else {
        func_005A6AB0(self->conn->agent, D_006C3F08, 0x200);
    }
    {
        struct Iface **api = &D_0064B4B0;
        struct Request *pr = &req;
        s32 length;

        func_005A48D8(pr, 0, sizeof(req));
        req.size = 0x800;
        req.a = 0;
        r = (*api)->open(self->conn, key, port, pr);
        if (r == 0) {
            (*api)->format(name, key);
            length = func_0057F260(host) + 0xD7;
            length += func_0057F260(self->conn->agent) + func_0057F260(path) * 2;
            func_0057DA20(self->conn->line, D_006C3F20, self->conn->host, name, port, length,
                          self->conn->agent, path, path, self->conn->agent, host, path);
            r = (*api)->write(self->conn->handle, self->conn->line,
                              func_0057F260(self->conn->line), &written);
            if (r == 0 && func_0057F260(self->conn->line) == written) {
                goto ok;
            }
            (*api)->close(self->conn->handle);
        }
    }
    func_00540EB0(self->conn->sock);
    return r;
ok:
    return 0;
}
