/* Handles one received message for a connection slot (names provisional, inferred from the code).
   C++: the callees defined earlier in the unit are declared throw(), which gives reorg the
   original's plain branch after the state test. */
union U16 { unsigned short s; unsigned char b[2]; };
struct Hdr { union U16 key; unsigned short size; union U16 len; };
struct Body {
    char pad0[4];
    unsigned char major;
    unsigned char minor;
    char pad6[2];
    unsigned short f8;
    char name[0x46];
};
struct Slot {
    unsigned int state;
    char pad4[0x10];
    char list[0x5A];
    unsigned short count;
    int f70;
    char pad74[4];
    unsigned short f78;
    char pad7A[10];
    int f84;
};
struct Ctx { int pad; };
struct Hooks {
    char pad0[0x2C];
    int (*f2C)(int, int, char *);
    char pad30[4];
    int (*f34)(int, int, char *);
};

extern struct Hooks *D_0064B710;
extern "C" {
int func_005A4724(void *d, const void *s, unsigned int n);
int func_00528770(unsigned char *p) throw();
int func_0052DD60(void *list);
int func_0052CC10(struct Ctx *c, struct Slot *s);
int func_005288E8(void) throw();
int func_0052CC90(struct Ctx *c, struct Slot *s, unsigned char *p);
int func_0052BDD8(struct Ctx *c, struct Slot *s);
}

extern "C" int func_0052BAD0(struct Ctx *c, struct Slot *s, unsigned short *msg, unsigned char *p)
{
    struct Body body;
    struct Hdr hdr;
    unsigned char *src;
    int peer;
    char *name;
    int one;
    int r;

    if ((msg[0] & 0x3FF) == 0) {
        return 0;
    }
    hdr.key.b[0] = p[0];
    hdr.key.b[1] = p[1];
    hdr.key.s &= 0xF800;
    if (hdr.key.s & 0x6000) {
        hdr.size = 4;
    } else {
        hdr.size = 2;
    }
    hdr.len.b[0] = p[0];
    hdr.len.b[1] = p[1];
    src = p + hdr.size;
    hdr.len.s &= 0x7FF;
    if (hdr.len.s >= 0x4D) {
        return 0xD2F5;
    }
    func_005A4724(&body, src, hdr.len.s);
    if (s->count == 0 && (s->state == 9 || s->state == 10)) {
        s->f78 = func_00528770(p);
        s->f70 = body.f8;
        s->count = msg[0] & 0x3FF;
        if (!func_0052DD60(s->list)) {
            s->state = 7;
            func_0052CC10(c, s);
            return 0xD2F7;
        }
    }
    if (s->state == 8) {
        return 0;
    }
    switch (s->state) {
    case 9:
        if (body.major >= 3 || body.minor != 0) {
            s->state = 1;
            func_0052CC10(c, s);
            return 0xD307;
        }
        /* fall through */
    case 10:
    case 12:
    case 13:
        if (s->f78 == 0) {
            s->f78 = func_00528770(p);
            s->f70 = body.f8;
        }
        one = 1;
        if (func_005288E8() != one && hdr.len.s == 0x4C) goto tail;
        if (func_005288E8() == one && hdr.len.s == 0xC) goto tail;
        break;
    default:
        s->state = 2;
        func_0052CC10(c, s);
        return 0;
    }
    if (hdr.len.s == 0x4C) {
        peer = s->f84;
        name = body.name;
        if (D_0064B710->f34(-1, peer, name) == 0) {
            s->f78 = func_00528770(p);
            r = func_0052CC90(c, s, p);
            if (!r) goto tail;
            return r;
        }
        D_0064B710->f2C(-1, peer, name);
        s->f78 = func_00528770(p);
        r = func_0052BDD8(c, s);
        if (!r) goto tail;
        return r;
    }
    r = func_0052CC90(c, s, p);
    if (r) return r;
tail:
    return 0;
}
