/* compiler: ee-gcc2.96-no-strict-aliasing */
/*
 * func_004FB698 (inferred): one step of the online session's request state machine. Unless the
 * session is active (+0x3C) or in state 1, it only clears the busy flag (+0x18C). Otherwise it
 * marks itself busy (2) and runs the handler of the current state (+0x188): most states begin an
 * operation on the connection context (+0x5A8, func_004F0A20 plus clearing two words of the
 * context), start a library request with a completion callback, record its result
 * (func_004F87B0 / func_004F8858 / func_004F88C8) and finish the operation once the status
 * (func_004F0D48) reports 1; some then copy the reply (lobby, user and room data) into the
 * session. When done it clears the busy flag and, if a state was pending, resets it to 0 and
 * raises +0x15C.
 *
 * Source forms that decide the code: begin()/poll() as inline helpers, the context re-read
 * through self->ctx for each clear (needs -fno-strict-aliasing), the join request local scoped to
 * its case so it shares the stack slot with the by-value name/config temporaries, and the state
 * read once in the guard and once in the switch.
 */
#include "types.h"

struct Ctx {
    s32 f0;
    s32 f4;
    char pad0[0x8];
    s32 f10;
    char pad1[0x14];
    s32 f28;
    char pad2[0x34];
    s32 f60;
    char pad3[0x20];
    s32 f84;
    s32 f88;
    char pad4[0x18];
    s32 fA4;
    char pad5[0x14C];
    s32 f1F4;
    char pad6[0x4];
    s32 f1FC;
    char pad7[0x5930];
    s32 f5B30;
    s32 f5B34;
};

struct Net {
    char pad0[0x3C];
    s32 f3C;
    char pad1[0x4];
    s32 f44;
    char pad2[0x114];
    s32 f15C;
    char pad3[0x14];
    s32 f174;
    char pad4[0x10];
    u32 state;
    s32 f18C;
    char pad5[0x418];
    Ctx *ctx;
    char pad6[0xC];
    s32 f5B8;
    char pad7[0x28];
    s32 f5E4;
    s32 f5E8;
    s32 f5EC;
    s32 f5F0;
    char pad8[0x440];
    s32 fA34;
    char pad9[0x4];
    s32 fA3C;
    char pad10[0x168];
    s32 fBA8;
    char pad11[0x40C];
    s32 fFB8;
    char pad12[0x20];
    s32 fFDC;
    char pad13[0x1248];
    s32 f2228;
};

struct Info { s32 d[0x27]; };
struct Table { s32 d[0x40]; };
struct Name { char d[100]; };
struct Cfg { signed char b0; char b1; short h2; unsigned short h4; unsigned short h6; };
struct JoinRequest {
    char name[0x14];
    s32 id;
    char host[0x40];
    char pass[0x20];
    s32 flags;
};

extern "C" void *memset(void *, int, unsigned int);
extern "C" s32 func_005A6AB0(void *, void *, s32) throw();
extern "C" s32 func_005A609C(void *, void *);
extern "C" void func_004F0A20(Net *self, void *ctx);
extern "C" void func_004F0A90(Net *self);
extern "C" s32 func_004F0D48(Net *self);
extern "C" void func_004F87B0(Net *self, s32 r);
extern "C" void func_004F8820(Net *self, s32 r);
extern "C" void func_004F8858(Net *self, s32 r);
extern "C" void func_004F8890(Net *self, s32 r);
extern "C" void func_004F88C8(Net *self, s32 r);
extern "C" void func_004FB548(Net *self);
extern "C" s32 func_0050B410(void);
extern "C" s32 func_0052E6D8(void);
extern "C" s32 func_0050DF58(Ctx *ctx, void *cb, void *cb2, Net *a, Net *b);
extern "C" s32 func_0050B498(Ctx *ctx, void *out, Net *self);
extern "C" s32 func_0050B5F8(void);
extern "C" s32 func_0050B848(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050B340(void *dst);
extern "C" s32 func_0050B7E8(Ctx *ctx);
extern "C" s32 func_0050B9B8(Ctx *ctx);
extern "C" s32 func_005054B0(Ctx *ctx, s32 *out, Net *self);
extern "C" s32 func_005055B8(void);
extern "C" s32 func_005051A8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_00505040(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_00505D40(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_004F5F28(Net *self);
extern "C" void func_004FB2F8(Net *self, s32 a, s32 b);
extern "C" void func_004FB3C0(Net *self, s32 a, s32 b);
extern "C" void func_004FB230(Net *self, Ctx *ctx, s32 id);
extern "C" void func_004FB480(Net *self, s32 id);
extern "C" s32 func_004FFBB8(Net *self);
extern "C" s32 func_004FF8E8(Net *self, Ctx *ctx, void *a, s32 b, void *c, void *d, s32 e);
extern "C" s32 func_004FF4A0(Net *self);
extern "C" s32 func_004FA1F0(Net *self, s32 a);
extern "C" s32 func_004FEFF8(Net *self, s32 a, s32 b);
extern "C" void *func_004FEFD8(Net *self, s32 a);
extern "C" s32 func_004FF318(Net *self, char *name, s32 a, s32 b, void *c, void *d);
extern "C" s32 func_004FEEE0(Net *self);
extern "C" s32 func_0050CB00(Ctx *ctx);
extern "C" s32 func_0050CDC8(Ctx *ctx);
extern "C" void func_004F6630(Net *self);
extern "C" void func_004F6780(Net *self);
extern "C" s32 func_004F68C8(Net *self);
extern "C" s32 func_004FA230(Net *self, s32 a);
extern "C" s32 func_0052FB78(s32 h);
extern "C" s32 func_0052FBD8(s32 h);
extern "C" s32 func_0052F880(s32 *out, s32 h);
extern "C" s32 func_0050D0E8(JoinRequest *req);
extern "C" s32 func_005068F8(Name name, void *cb, Net *self);
extern "C" s32 func_005078A0(Name name, s32 a, void *cb, Net *self);
extern "C" s32 func_005082B8(Name name, s32 a, void *cb, Net *self);
extern "C" s32 func_005073D0(Name name, s32 a, void *cb, Net *self);
extern "C" s32 func_005070E8(Name name, s32 a, void *cb, Net *self);
extern "C" s32 func_00508488(s32 a, Cfg cfg, void *cb, Net *self);
extern "C" s32 func_00508618(s32 a, Cfg cfg, void *cb, Net *self);
extern "C" void func_004F10D0();
extern "C" void func_004F1298();
extern "C" void func_004F17A0();
extern "C" void func_004F1AE0();
extern "C" void func_004F1C68();
extern "C" void func_004F1DA0();
extern "C" void func_004F20F0();
extern "C" void func_004F2598();
extern "C" void func_004F26E8();
extern "C" void func_004F29C8();
extern "C" void func_004F2B50();
extern "C" void func_004F2D68();
extern "C" void func_004F2FD8();
extern "C" void func_004F3200();
extern "C" void func_004F33D0();
extern "C" void func_004F3510();
extern "C" void func_004F3608();
extern "C" void func_004F3740();
extern "C" void func_004F39A0();
extern "C" void func_004F3AB8();
extern "C" void func_004F3D08();
extern "C" void func_004F3FC8();
extern "C" void func_004F4230();
extern "C" void func_004F44E0();
extern "C" void func_004F4680();
extern "C" void func_004F47F0();
extern "C" void func_004F4CD8();
extern "C" void func_004F4F68();
extern "C" void func_004F50D8();
extern "C" void func_004F5228();
extern "C" void func_004F53F0();
extern "C" void func_004F5698();
extern "C" void func_004F5928();
extern "C" void func_004F5A60();
extern "C" void func_004F5B78();
extern "C" void func_004F5DB0();
extern "C" void func_004F60A0();
extern "C" void func_004F62E8();
extern "C" void func_004F6988();
extern "C" void func_004F6C40();
extern "C" void func_004F7730();
extern "C" void func_004F77B8();
extern "C" void func_004F7840();
extern "C" void func_004F78C8();
extern "C" void func_004F7950();
extern "C" void func_004F79D8();
extern "C" void func_004F7A60();
extern "C" void func_004F7E38();
extern "C" void func_004F8150();
extern "C" void func_004FD778();
extern "C" void func_004FDAF0();
extern "C" void func_004FDE18();
extern "C" void func_004FE0D0();
extern "C" void func_004FE3D0();
extern "C" void func_004FE5F0();
extern "C" void func_004FE9E8();
extern "C" void func_004FED70();
extern "C" void func_004FFFE8();
extern "C" void func_00500198();
extern "C" void func_005008B8();
extern "C" void func_00500B20();
extern "C" s32 func_00505040(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_005051A8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_00505D40(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050BA18(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050BCB8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050BF28(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050BFB0(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C040(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C170(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C278(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C300(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C480(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C508(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C600(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C680(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C780(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C800(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C880(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C900(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050C980(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050CA00(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050CA80(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050CC48(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050CCC8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050CD48(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050CE28(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050CEA8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050CF28(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050CFA8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050D150(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050D1D0(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050D250(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050D2D0(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050D350(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050D790(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050D9A0(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050DC58(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050DCD8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050DE58(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050E048(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050E1B0(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050E228(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050E6E8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050E8C8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050E940(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050E9D0(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050EA48(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050EB38(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050EBD8(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050ECF0(Ctx *ctx, void *cb, Net *self);
extern "C" s32 func_0050EF10(Ctx *ctx, void *cb, Net *self);

static inline void begin(Net *self, void *ctx) {
    func_004F0A20(self, ctx);
    self->ctx->f5B30 = 0;
    self->ctx->f5B34 = 0;
}

static inline void poll(Net *self) {
    if (func_004F0D48(self) == 1)
        func_004F0A90(self);
}

extern "C" void func_004FB698(Net *self) {
    s32 local;
    if (self->f3C == 0 && self->state != 1) {
        self->f18C = 0;
        return;
    }
    self->f18C = 2;
    switch (self->state) {
    case 0x0:
        func_004FB548(self);
        break;
    case 0x2:
    {
        s32 r = func_0050B410();
        if (r != 0) {
            func_004F87B0(self, r);
        } else {
            r = func_0052E6D8();
            if (r != 0)
                func_004F8820(self, r);
        }
        break;
    }
    case 0x3:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050DF58(ctx, (void *)func_004F10D0, (void *)func_004F1298, self, self));
        poll(self);
        break;
    }
    case 0x4:
    {
        begin(self, 0);
        Ctx *ctx = self->ctx;
        func_004F87B0(self, func_0050B498(ctx, (char *)ctx + 0x1D8, self));
        poll(self);
        break;
    }
    case 0x5:
        self->f5E4 = 0;
        self->f5E8 = 0;
        if (func_0050B5F8() != 0)
            func_004F8890(self, 3);
        break;
    case 0x6:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050B848(ctx, (void *)func_004F17A0, self));
        poll(self);
        if (func_004F0D48(self) == 1)
            func_0050B340((char *)self + 0xAF8);
        break;
    }
    case 0x7:
        func_004F87B0(self, func_0050B7E8(self->ctx));
        break;
    case 0x8:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050D790(ctx, (void *)func_004F1AE0, self));
        poll(self);
        break;
    }
    case 0x9:
        begin(self, self->ctx);
        func_004F87B0(self, func_0050E6E8(self->ctx, (void *)func_004F1C68, self));
        poll(self);
        break;
    case 0xA:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050CFA8(ctx, (void *)func_004F1DA0, self));
        poll(self);
        break;
    }
    case 0xB:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050D1D0(ctx, (void *)func_004F20F0, self));
        poll(self);
        break;
    }
    case 0xC:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050D150(ctx, (void *)func_004F20F0, self));
        poll(self);
        break;
    }
    case 0xD:
        func_004F87B0(self, func_0050B9B8(self->ctx));
        break;
    case 0xE:
        begin(self, 0);
        func_004F8858(self, func_005054B0(self->ctx, &local, self));
        poll(self);
        break;
    case 0xF:
        if (func_005055B8() != 0)
            func_004F8890(self, 4);
        self->f5B8 = 0;
        self->f5E4 = 0;
        self->f5EC = 0;
        self->f5F0 = 0;
        break;
    case 0x10:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F8858(self, func_005051A8(ctx, (void *)func_004FFFE8, self));
        poll(self);
        if (func_004F0D48(self) == 1)
            func_005A609C((char *)self + 0x3F28, (char *)self->ctx + 0x268);
        break;
    }
    case 0x11:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F8858(self, func_00505040(ctx, (void *)func_00500198, self));
        poll(self);
        break;
    }
    case 0x12:
        func_004F8858(self, func_005054B0(self->ctx, &local, self));
        break;
    case 0x13:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C900(ctx, (void *)func_004F5DB0, self));
        poll(self);
        if (func_004F0D48(self) == 1)
            func_004FB2F8(self, func_004F5F28(self), ctx->f28);
        break;
    }
    case 0x14:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F8858(self, func_00505D40(ctx, (void *)func_005008B8, self));
        poll(self);
        if (func_004F0D48(self) == 1) {
            func_004FB230(self, ctx, self->fA3C);
            self->f5EC = 1;
            func_004FB480(self, self->fA3C);
            self->f5E4 = 1;
            self->fA34 = 0;
        }
        break;
    }
    case 0x15:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C508(ctx, (void *)func_00500B20, self));
        poll(self);
        if (func_004F0D48(self) == 1) {
            func_005A6AB0((char *)self + 0x222C, (char *)self + 0x8A1, 0xC);
            *(Info *)((char *)self + 0x218C) = *(Info *)((char *)self->ctx + 0x1F8);
            self->fA3C = ctx->f28;
            func_005A6AB0((char *)self + 0x9E1, (char *)ctx + 0x30, 0x20);
        }
        break;
    }
    case 0x36:
        if (func_004FFBB8(self) != 0)
            self->f174 = 0;
        else
            self->f174 = 0xFFFFFF;
        break;
    case 0x38:
    {
        Ctx *ctx = self->ctx;
        if (func_004FF8E8(self, ctx, (char *)ctx + 0x40, ctx->f60, (char *)ctx + 0x64, (char *)ctx + 0x84, ctx->fA4) != 0 && func_004FF4A0(self) != 0
            && func_004FA1F0(self, 1) != 0)
            self->f174 = 0;
        else
            self->f174 = 0xFFFFFF;
        break;
    }
    case 0x39:
    {
        Ctx *ctx = self->ctx;
        if (func_004FEFF8(self, ctx->f0, ctx->f4) != 0)
            self->f174 = 0;
        else
            self->f174 = 0xFFFFFF;
        break;
    }
    case 0x3A:
    {
        Ctx *ctx = self->ctx;
        char *name = (char *)func_004FEFD8(self, ctx->f0);
        if (func_004FF318(self, name, ((Ctx *)func_004FEFD8(self, ctx->f0))->f10, self->f44, (char *)ctx + 4, (char *)ctx + 0x24) != 0 && func_004FF4A0(self) != 0
            && func_004FA1F0(self, 0) != 0)
            self->f174 = 0;
        else
            self->f174 = 0xFFFFFF;
        break;
    }
    case 0x3C:
        if (func_004FEEE0(self) != 0)
            self->f174 = 0;
        else
            self->f174 = 0xFFFFFF;
        break;
    case 0x16:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050DCD8(ctx, (void *)func_004F2598, self));
        poll(self);
        break;
    }
    case 0x17:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050E228(ctx, (void *)func_004F26E8, self));
        poll(self);
        break;
    }
    case 0x18:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C480(ctx, (void *)func_004F29C8, self));
        poll(self);
        break;
    }
    case 0x19:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C600(ctx, (void *)func_004F2B50, self));
        poll(self);
        if (func_004F0D48(self) == 1) {
            *(Info *)((char *)self + 0xB0C) = *(Info *)((char *)self->ctx + 0x1F4);
            self->fBA8 = self->ctx->f28;
        }
        break;
    }
    case 0x1A:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050D9A0(ctx, (void *)func_004F7E38, self));
        poll(self);
        break;
    }
    case 0x1B:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C780(ctx, (void *)func_004F2D68, self));
        poll(self);
        break;
    }
    case 0x1C:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C980(ctx, (void *)func_004F2FD8, self));
        poll(self);
        break;
    }
    case 0x1D:
        func_004F87B0(self, func_0050CB00(self->ctx));
        func_004F0D48(self);
        break;
    case 0x1E:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C300(ctx, (void *)func_004F8150, self));
        poll(self);
        break;
    }
    case 0x1F:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050BA18(ctx, (void *)func_004F3200, self));
        poll(self);
        if (func_004F0D48(self) == 1) {
            Ctx *c = self->ctx;
            self->fFDC = c->f1F4;
            self->fBA8 = c->f1FC;
            *(Info *)((char *)self + 0xB0C) = *(Info *)((char *)c + 0x200);
        }
        break;
    }
    case 0x20:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050BCB8(ctx, (void *)func_004F33D0, self));
        poll(self);
        if (func_004F0D48(self) == 1) {
            memset((char *)self + 0xFDC, 0, 0x44);
            self->fFDC = -1;
        }
        break;
    }
    case 0x21:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050BF28(ctx, (void *)func_004F3510, self));
        poll(self);
        break;
    }
    case 0x22:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C170(ctx, (void *)func_004F3608, self));
        poll(self);
        break;
    }
    case 0x23:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050BFB0(ctx, (void *)func_004F3740, self));
        poll(self);
        break;
    }
    case 0x24:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C040(ctx, (void *)func_004F39A0, self));
        poll(self);
        break;
    }
    case 0x3D:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C880(ctx, (void *)func_004F3AB8, self));
        poll(self);
        if (func_004F0D48(self) == 1 && ctx->f28 == self->fFDC)
            *(Table *)((char *)self + 0x60C) = *(Table *)((char *)self->ctx + 0x220);
        break;
    }
    case 0x3E:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050CA00(ctx, (void *)func_004F3D08, self));
        poll(self);
        break;
    }
    case 0x3F:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050CA80(ctx, (void *)func_004F3FC8, self));
        poll(self);
        break;
    }
    case 0x40:
        begin(self, self->ctx);
        func_004F87B0(self, func_0050E048(self->ctx, (void *)func_004F4230, self));
        poll(self);
        break;
    case 0x41:
        func_004F87B0(self, func_0050CD48(self->ctx, (void *)func_004F44E0, self));
        break;
    case 0x42:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050CC48(ctx, (void *)func_004F4680, self));
        poll(self);
        break;
    }
    case 0x43:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050CCC8(ctx, (void *)func_004F47F0, self));
        poll(self);
        break;
    }
    case 0x44:
        func_004F87B0(self, func_0050CDC8(self->ctx));
        break;
    case 0x46:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050CE28(ctx, (void *)func_004F4CD8, self));
        poll(self);
        break;
    }
    case 0x47:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050CEA8(ctx, (void *)func_004F4F68, self));
        poll(self);
        break;
    }
    case 0x48:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050CF28(ctx, (void *)func_004F50D8, self));
        poll(self);
        break;
    }
    case 0x27:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050DC58(ctx, (void *)func_004F5228, self));
        poll(self);
        break;
    }
    case 0x28:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C680(ctx, (void *)func_004F53F0, self));
        poll(self);
        break;
    }
    case 0x29:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050E1B0(ctx, (void *)func_004F5698, self));
        poll(self);
        break;
    }
    case 0x2A:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050D250(ctx, (void *)func_004F5928, self));
        poll(self);
        break;
    }
    case 0x2B:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050D2D0(ctx, (void *)func_004F5A60, self));
        poll(self);
        break;
    }
    case 0x2C:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050D350(ctx, (void *)func_004F5B78, self));
        poll(self);
        break;
    }
    case 0x2D:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C900(ctx, (void *)func_004F5DB0, self));
        poll(self);
        if (func_004F0D48(self) == 1)
            func_004FB3C0(self, func_004F5F28(self), ctx->f28);
        break;
    }
    case 0x2E:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C278(ctx, (void *)func_004F60A0, self));
        poll(self);
        break;
    }
    case 0x2F:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C508(ctx, (void *)func_004F62E8, self));
        poll(self);
        if (func_004F0D48(self) == 1) {
            func_005A6AB0((char *)self + 0x222C, (char *)self + 0x728, 0xC);
            *(Info *)((char *)self + 0x218C) = *(Info *)((char *)self->ctx + 0x1F8);
            self->fA3C = ctx->f28;
        }
        break;
    }
    case 0x30:
        func_004F6630(self);
        break;
    case 0x31:
        func_004F6780(self);
        break;
    case 0x32:
        self->fFB8 = 0;
        func_004FA230(self, func_004F68C8(self));
        func_004F8820(self, func_0052FB78(self->f2228));
        func_004F0D48(self);
        break;
    case 0x33:
    {
        func_004F8820(self, func_0052FBD8(self->f2228));
        if (func_004F0D48(self) == 1) {
            func_0052F880(&local, self->f2228);
            if (func_004F68C8(self) != 0 && local < 2) {
                JoinRequest req;
                func_005A6AB0(req.name, (char *)self + 0xAF8, 0x11);
                req.id = self->fA3C;
                req.host[0] = 0;
                req.pass[0] = 0;
                req.flags = 0;
                func_004F87B0(self, func_0050D0E8(&req));
            }
            self->f5E8 = 0;
            self->f5EC = 0;
            self->f5E4 = 0;
            self->f2228 = 0;
        }
        break;
    }
    case 0x34:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050C800(ctx, (void *)func_004F6988, self));
        poll(self);
        break;
    }
    case 0x35:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F87B0(self, func_0050DE58(ctx, (void *)func_004F6C40, self));
        poll(self);
        break;
    }
    case 0x49:
    {
        Ctx *ctx = self->ctx;
        begin(self, (char *)ctx + 0x1C0);
        func_004F87B0(self, func_0050E8C8(ctx, (void *)func_004FD778, self));
        poll(self);
        break;
    }
    case 0x4A:
    {
        Ctx *ctx = self->ctx;
        begin(self, (char *)ctx + 0xB4);
        func_004F87B0(self, func_0050E940(ctx, (void *)func_004FDAF0, self));
        poll(self);
        break;
    }
    case 0x4B:
    {
        Ctx *ctx = self->ctx;
        begin(self, (char *)ctx + 0xAC);
        func_004F87B0(self, func_0050E9D0(ctx, (void *)func_004FDE18, self));
        poll(self);
        break;
    }
    case 0x4C:
    {
        Ctx *ctx = self->ctx;
        begin(self, (char *)ctx + 0xAC);
        func_004F87B0(self, func_0050EA48(ctx, (void *)func_004FE0D0, self));
        poll(self);
        break;
    }
    case 0x4D:
    {
        Ctx *ctx = self->ctx;
        begin(self, (char *)ctx + 0xAC);
        func_004F87B0(self, func_0050EB38(ctx, (void *)func_004FE3D0, self));
        poll(self);
        break;
    }
    case 0x4E:
    {
        Ctx *ctx = self->ctx;
        begin(self, (char *)ctx + 0x98);
        func_004F87B0(self, func_0050EBD8(ctx, (void *)func_004FE5F0, self));
        poll(self);
        break;
    }
    case 0x4F:
    {
        Ctx *ctx = self->ctx;
        begin(self, (char *)ctx + 0xAC);
        func_004F87B0(self, func_0050ECF0(ctx, (void *)func_004FE9E8, self));
        poll(self);
        break;
    }
    case 0x50:
    {
        Ctx *ctx = self->ctx;
        begin(self, (char *)ctx + 0xAC);
        func_004F87B0(self, func_0050EF10(ctx, (void *)func_004FED70, self));
        poll(self);
        break;
    }
    case 0x51:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F88C8(self, func_005068F8(*(Name *)((char *)ctx + 0x15), (void *)func_004F7730, self));
        poll(self);
        break;
    }
    case 0x52:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F88C8(self, func_00508488(ctx->f84, *(Cfg *)((char *)ctx + 0x7A), (void *)func_004F77B8, self));
        poll(self);
        break;
    }
    case 0x53:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F88C8(self, func_005078A0(*(Name *)((char *)ctx + 0x15), ctx->f84, (void *)func_004F7840, self));
        poll(self);
        break;
    }
    case 0x54:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F88C8(self, func_00508618(ctx->f84, *(Cfg *)((char *)ctx + 0x7A), (void *)func_004F78C8, self));
        poll(self);
        break;
    }
    case 0x55:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F88C8(self, func_005082B8(*(Name *)((char *)ctx + 0x15), ctx->f84, (void *)func_004F7950, self));
        poll(self);
        break;
    }
    case 0x56:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F88C8(self, func_005073D0(*(Name *)((char *)ctx + 0x15), ctx->f88, (void *)func_004F79D8, self));
        poll(self);
        break;
    }
    case 0x57:
    {
        Ctx *ctx = self->ctx;
        begin(self, ctx);
        func_004F88C8(self, func_005070E8(*(Name *)((char *)ctx + 0x15), ctx->f84, (void *)func_004F7A60, self));
        poll(self);
        break;
    }
    }
    self->f18C = 0;
    if (self->state != 0) {
        self->state = 0;
        self->f15C = 1;
    }
}
