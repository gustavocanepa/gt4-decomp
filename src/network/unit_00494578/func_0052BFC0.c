/* Takes one incoming request and starts a slot for it (names provisional, inferred from the code):
   reads a small header from the message, copies the body, allocates and fills a slot, then acts on
   the slot's state. Returns 0 for an empty message, 0xD2F5 for a body that is too long, 0xD2F7 when
   no slot could be started, or a later error. Only state 0 is special, and the jump table sends every
   other value to the same code, so the case values listed besides 0 and 13 are not recoverable; a
   table needs several separate values, and 13 sets its size. */
struct Addr { int a, b; };
union U16 { unsigned short s; unsigned char b[2]; };
struct Hdr { union U16 key; unsigned short size; union U16 len; };
struct Info { int f0, f4, f8, fC; };
struct Slot {
    int state;
    int pad4;
    struct Addr addr;
    int id;
    char f14[0x18];
    char f2C[0x18];
    char f44[8];
    char f4C[8];
    char pad54[0x10];
    int f64;
    int f68;
    char pad6C[2];
    unsigned short count;
    int f70;
    unsigned short f74;
    unsigned short f76;
    unsigned short f78;
    char pad7A[10];
    int f84;
    char pad88[4];
    int f8C;
    int f90;
    char pad94[0x404];
    int f498;
};
struct Ctx {
    char pad0[0x50];
    int f50, f54, f58;
    char pad5C[0x14];
    int f70;
    char pad74[0x14];
    int f88, f8C, f90;
};
struct Hooks {
    char pad0[0x18];
    void (*f18)(int, int, void *);
    void (*f1C)(int, int, void *);
    char pad20[0xC];
    void (*f2C)(int, int, void *);
    char pad30[0x24];
    void (*f54)(void *);
};
extern struct Hooks *D_0064B710;
extern unsigned char *func_005288B0(unsigned short *msg);
extern struct Slot *func_0052AA18(struct Ctx *ctx);
extern int func_00528940(int v);
extern int func_00528770(unsigned char *p);
extern int func_005A4724(void *d, const void *s, unsigned int n);
extern int func_0053A860(void *p);
extern int func_0052D448(void *p, int v);
extern int func_0052CC10(struct Ctx *ctx, struct Slot *s);
extern int func_0052D390(int x, struct Info **out);
extern int func_005288E8(void);
extern int func_0052BDD8(struct Ctx *ctx, struct Slot *s);

int func_0052BFC0(struct Ctx *ctx, struct Slot **out, unsigned short *msg, struct Addr addr, int id)
{
    struct Slot *s;
    unsigned char *p;
    int status = 0;
    unsigned char *src;
    struct Info *info;
    unsigned short buf[0x28];
    struct Hdr hdr;
    char first[0x40];
    char second[0x40];

    if ((msg[0] & 0x3FF) == 0) {
        return 0;
    }
    p = func_005288B0(msg);
    hdr.key.b[0] = p[0];
    hdr.key.b[1] = p[1];
    hdr.key.s &= 0xF800;
    if (hdr.key.s & 0x6000) {
        hdr.size = 4;
    } else {
        hdr.size = 2;
    }
    src = p + hdr.size;
    hdr.len.b[0] = p[0];
    hdr.len.b[1] = p[1];
    hdr.len.s &= 0x7FF;
    if (hdr.len.s < 0x4D) goto copy;
    return 0xD2F5;
init:
    *out = s;
    s->f74 = func_00528940(0xFFFF);
    s->f76 = 0;
    s->f78 = func_00528770(p);
    s->id = id;
    s->count = msg[0] & 0x3FF;
    s->f70 = buf[4];
    s->addr = addr;
    func_0053A860(s->f44);
    func_0053A860(s->f4C);
    s->f68 = 1000;
    s->f64 = 0;
    if (func_0052D448(s->f14, ctx->f54) || func_0052D448(s->f2C, ctx->f58)) {
        s->state = 7;
        func_0052CC10(ctx, s);
        status = 0xD2F7;
    }
    goto started;
copy:
    func_005A4724(buf, src, hdr.len.s);
    s = func_0052AA18(ctx);
    if (s) goto init;
    status = 0xD2F7;
started:
    if (status) {
        return status;
    }
    switch (s->state) {
    case 0:
        info = 0;
        if (buf[3]) {
            int r = func_0052D390(buf[3], &info);
            if (r) return r;
        }
        if (info) {
            s->f90 = info->f4;
            s->f8C = info->f8;
            s->f498 = info->fC;
        } else {
            int v88 = ctx->f88;
            int v8C = ctx->f8C;
            int v90 = ctx->f90;
            s->f90 = v88;
            s->f8C = v8C;
            s->f498 = v90;
        }
        if (ctx->f70 == 0) {
            s->state = 8;
            break;
        }
        s->state = 10;
        if (func_005288E8() == 1) {
            D_0064B710->f54(second);
            D_0064B710->f2C(-1, s->f84, second);
            D_0064B710->f1C(-1, ctx->f50, first);
            D_0064B710->f18(-1, s->f84, first);
        }
        status = func_0052BDD8(ctx, s);
        if (status) {
            s->state = 2;
            func_0052CC10(ctx, s);
        }
        return status;
    case 2:
    case 5:
    case 9:
    case 13:
        goto reset;
    default:
    reset:
        s->state = 2;
        status = func_0052CC10(ctx, s);
        break;
    }
    return status;
}
