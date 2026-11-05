/* Sends a scatter-gather packet through each link of a list (names provisional, inferred from the
   code). When flag 0x8000 survives the check at the top, the fragments are merged into the sender's
   buffer first. Each link of type 0xD gets a built header appended to the fragment list for one send.
   Returns 0, 2 for bad arguments, 0xD2F2 for a null sender, or the send's error. */
struct IoVec { void *base; int len; };
struct IoList {
    IoVec iov[8];
    unsigned int total;
    int count;
};
struct Sender { char pad[0x48]; char *buffer; char pad4c[0x10]; unsigned int mtu; };
struct Link {
    int type;
    char pad4[0x58];
    unsigned short tag;
    char pad5e[0x16];
    unsigned short pending;
    char pad76[6];
    int sent;
};
struct Ops { char pad[0x3C]; int (*alloc)(int, int, void *, unsigned int); };
extern "C" Ops *D_0064B710;
extern "C" int func_005288E8(void);
extern "C" void *func_005A4724(void *, const void *, int);
extern "C" void func_0052AA88(Sender *, Link *, unsigned int, unsigned int, char *);
extern "C" int func_0052AB68(Sender *, void *, IoList *, int, int);
extern "C" unsigned short func_00528770(char *);
/* The int gives the union integer alignment: two shorts alone would get a 16-byte stack slot. */
union Header { struct { unsigned short kind, size; }; int word; };

extern "C" int func_00529A78(Sender *self, Link **links, int count, unsigned short flags, IoList *packet) {
    int token = 0;
    int i;
    IoList list;
    char buf[16];
    Header h;
    if (!self) return 0xD2F2;
    if (!links) return 2;
    if (!count || !packet || !packet->total || self->mtu < packet->total) return 2;
    if (func_005288E8() != 1) flags &= 0x7FFF;
    if (flags & 0x8000) {
        int off = 0;
        for (i = packet->count - 1; i >= 0; i--) {
            func_005A4724(self->buffer + off, packet->iov[i].base, packet->iov[i].len);
            off += packet->iov[i].len;
        }
        token = D_0064B710->alloc(-1, 0xFFFE, self->buffer, packet->total);
        list.count = 0;
        list.total = 0;
        if (list.count < 8) {
            int c = list.count;
            list.iov[c].base = self->buffer;
            list.iov[c].len = packet->total;
            list.total += list.iov[c].len;
            list.count++;
        }
    } else {
        list = *packet;
    }
    for (i = 0; i < count; i++) {
        if (!links[i] || links[i]->type != 0xD) continue;
        func_0052AA88(self, links[i], flags, list.total, buf);
        ((char *)&h)[0] = buf[0];
        ((char *)&h)[1] = buf[1];
        h.kind &= 0xF800;
        if (h.kind & 0x6000) h.size = 4; else h.size = 2;
        if (list.count < 8) {
            /* Binding a reference delays the load, which gives the original's instruction order. */
            const unsigned short &n = h.size;
            int c = list.count;
            list.iov[c].len = n;
            list.iov[c].base = buf;
            list.total += list.iov[c].len;
            list.count++;
        }
        int r = func_0052AB68(self, &links[i]->pad4[0x10], &list, 0x8000, token);
        list.count--;
        list.total -= list.iov[list.count].len;
        if (r && (unsigned short)(flags & 0x4000)) {
            links[i]->pending--;
            return r;
        }
        if (links[i]->tag == 0 && (unsigned short)(flags & 0x4000)) links[i]->tag = func_00528770(buf);
        if ((unsigned short)(flags & 0x1000)) links[i]->sent++;
    }
    return 0;
}
