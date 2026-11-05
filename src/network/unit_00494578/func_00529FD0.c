/* Sends a request on a connection (names provisional, inferred from the code): reads a small header
   from the pending packet and either forwards it as is or builds a fresh header and sends the list
   with it appended. Returns 0, 0xD2F2 for a null connection, 2 for bad arguments, 3 with no pending
   packet, or the send's error. */
union U16 { unsigned short s; unsigned char b[2]; };
struct Item { char *base; int len; };
struct Buf { struct Item iov[8]; unsigned int total; int count; };
struct Conn {
    char pad0[0x24];
    char list[0x10];
    int f34;
    char pad38[0xC];
    int f44;
    char pad48[0x14];
    unsigned int f5C;
    char pad60[0x10];
    int f70;
};
struct Packet { unsigned int f0; char pad4[0x14]; unsigned char hdr[2]; };
extern int func_005288E8(void);
extern struct Packet *func_0052DD98(void *list);
extern int func_0052AD00(struct Conn *c, void *list, unsigned int flags, struct Packet *p, struct Buf *b);
extern void func_0052AA88(struct Conn *c, int zero, unsigned int flags, unsigned int len, char *out);
extern int func_0052AB68(struct Conn *c, void *list, struct Buf *b, unsigned int flags, int zero);

int func_00529FD0(struct Conn *c, unsigned short flags, struct Buf *b)
{
    struct {
        union U16 a;
        union U16 k;
        unsigned short size;
        unsigned short size2;
    } h;
    char text[0x10];
    struct { union U16 a; union U16 b; } t;
    struct Packet *p;
    unsigned char *src;
    void *list;
    int mode;
    char *out;
    int n;
    int e;

    h.size2 = 0;
    if (!c) {
        return 0xD2F2;
    }
    if (!b || b->total == 0 || c->f5C < b->total) {
        return 2;
    }
    if (flags & 0x4000) {
        return 2;
    }
    mode = func_005288E8();
    if (mode != 2) {
        return 0;
    }
    flags &= 0x7FFF;
    if (!c->f34) {
        return 0;
    }
    if (flags & 0x1000) {
        c->f44 = 1;
    }
    list = c->list;
    p = func_0052DD98(list);
    if (!p) {
        return 3;
    }
    src = p->hdr;
    h.a.b[0] = src[0];
    h.a.b[1] = src[1];
    h.a.s &= 0x7FF;
    h.k.b[0] = src[0];
    h.k.b[1] = src[1];
    h.k.s &= 0xF800;
    if (h.k.s & 0x6000) {
        h.size = 4;
    } else {
        h.size = mode;
    }
    h.size2 = (flags & 0x6000) ? 4 : 2;
    if (p->f0 && h.size < p->f0 && h.size >= h.size2 &&
        h.a.s + b->total + h.size <= c->f5C) {
        e = func_0052AD00(c, list, flags, p, b);
        if (!e) goto tail;
        goto far;
    }
    out = text;
    func_0052AA88(c, 0, flags, b->total, out);
    t.a.b[0] = text[0];
    t.a.b[1] = text[1];
    t.a.s &= 0xF800;
    if (t.a.s & 0x6000) {
        h.size = 4;
    } else {
        h.size = 2;
    }
    n = b->count;
    if (n < 8) {
        b->iov[n].len = h.size;
        b->iov[n].base = out;
        b->total += h.size;
        b->count++;
    }
    {
        int e = func_0052AB68(c, list, b, flags, 0);
        if (e) return e;
    }
    b->count--;
    b->total -= b->iov[b->count].len;
tail:
    return 0;
far:
    return e;
}
