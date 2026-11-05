/* Applies a request to one slot of a table (names provisional, inferred from the code): closes the
   slot, notifies, or opens its two connections depending on the table's status. Returns 0, 0xD4EC
   for an index out of range, or the first connection error. This one is C, not C++: the address
   struct is passed by value without a temporary, which C++ would make. */
struct Addr { int a, b; };
struct Request {
    char pad0[4];
    struct Addr first;
    struct Addr second;
    unsigned short firstPort;
    unsigned short secondPort;
    unsigned short index;
    unsigned char closing;
    unsigned char notify;
    char data[0x40];
    unsigned short limit;
    unsigned short tag;
    int cookie;
};
struct Slot {
    int state;
    int conn[2];
    char pad0c[0x20];
    unsigned short limit;
    char pad2e[0x16];
};
struct Table {
    int owner;
    char pad4[0x80];
    struct Slot *slots;
    char pad88[0x14];
    unsigned short count;
    char pad9e[0x26];
    unsigned short maxLimit;
    char padc6[2];
    int cookie;
};
struct Connect {
    struct Addr addr;
    int port;
    unsigned int index;
    unsigned short tag;
    void *send;
    void *recv;
    struct Table *table;
};
struct Ops1 { char pad[0x24]; void (*notify)(int, int, void *); };
struct Ops2 { char pad[0x70]; int (*invalid)(struct Addr); };
extern struct Ops1 *D_0064B710;
extern struct Ops2 *D_0064B4B0;
extern void func_00526040(struct Table *, int *, unsigned short *);
extern void *func_005A48D8(void *, int, int);
extern void func_00529760(int, unsigned int);
extern int func_00527D38(struct Table *, struct Connect *, int *);
extern int func_005293D0(int, struct Connect *, int *);
extern int func_0052A3B0(int, struct Connect *, int *);
extern void func_005257B0(void);
extern void func_005256A8(void);

extern int func_00526438(struct Table *self, int unused, const char *in) {
    struct Connect c;
    struct Request req;
    unsigned short id = 0xFFFE;
    int status = 0;
    int ret = 6;
    struct Slot *slot;
    int *conn;
    int n;
    int r;
    int cookie;
    __builtin_memcpy(&req, (const void *)in, sizeof(req));
    c.index = req.index;
    if (c.index >= self->count) return 0xD4EC;
    slot = &self->slots[c.index];
    slot->limit = req.limit;
    if (self->maxLimit < req.limit) self->maxLimit = req.limit;
    func_00526040(self, &status, &id);
    if (status == 0 || status == 5) {
        if (req.closing) {
            if (c.index) {
                struct Slot *first = self->slots;
                *slot = *first;
                func_005A48D8(first, 0, 0x44);
                first->conn[0] = 0;
                first->conn[1] = 0;
                if (slot->conn[0]) func_00529760(slot->conn[0], c.index);
                if (slot->conn[1]) func_00529760(slot->conn[1], c.index);
                slot->limit = req.limit;
            }
            return 0;
        }
        if (status == 0 && req.notify) {
            cookie = req.cookie;
            slot->state = 5;
            self->cookie = cookie;
            if (D_0064B710) D_0064B710->notify(-1, 0, req.data);
            return 0;
        }
        c.recv = (void *)func_005257B0;
        c.send = (void *)func_005256A8;
        c.addr = req.first;
        c.tag = req.tag;
        c.port = req.firstPort;
        c.table = self;
        for (n = 2, conn = &slot->conn[0]; n; n--) {
            if (!D_0064B4B0->invalid(c.addr) && c.port) {
                r = func_00527D38(self, &c, conn);
                if (r) return r;
                if (*conn == 0) {
                    if (status == 0) ret = func_005293D0(self->owner, &c, conn);
                    else ret = func_0052A3B0(self->owner, &c, conn);
                }
                if (ret) return ret;
                slot->state = 2;
            }
            c.addr = req.second;
            c.port = req.secondPort;
            conn = &slot->conn[1];
        }
        return 0;
    }
    if (status == 6) {
        c.recv = (void *)func_005257B0;
        c.send = (void *)func_005256A8;
        c.addr = req.first;
        c.port = req.firstPort;
        c.table = self;
        for (n = 2, conn = &slot->conn[0]; n; n--) {
            if (!D_0064B4B0->invalid(c.addr) && c.port) {
                r = func_00527D38(self, &c, conn);
                if (r) return r;
                if (*conn == 0) {
                    r = func_0052A3B0(self->owner, &c, conn);
                    if (r) return r;
                }
                slot->state = 2;
            }
            c.addr = req.second;
            c.port = req.secondPort;
            conn = &slot->conn[1];
        }
    }
    return 0;
}
