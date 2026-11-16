/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Cfg { char pad0[0xC]; s32 mode; char pad10[0x1AA4 - 0x10]; s32 f1AA4; };
struct Global { char pad[0x39DF8]; s32 f39DF8; };

class Ctl {
public:
    char pad[0xF0];
    s32 fF0;
    char pad2[0x974 - 0xF4];
    virtual void v0(s32);
};

#define V1(n) virtual void n(s32);
#define V10(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3) V1(n##4) V1(n##5) V1(n##6) V1(n##7) V1(n##8) V1(n##9)
class RaceB {
public:
    char pad0[0x64];
    V10(a) V10(b) V10(c) V10(d) V10(e) V1(f0) V1(f1) V1(f2) V1(f3) V1(f4) V1(f5)
    virtual void load(Cfg *);
    V1(g7) V1(g8) V1(g9) V10(h) V10(i) V10(j) V10(k)
    virtual void start(s32);
    V1(l1) V1(l2) V1(l3) V1(l4) V1(l5) V1(l6) V1(l7) V1(l8) V1(l9) V10(m) V10(n) V10(o) V10(p)
    V1(q0) V1(q1) V1(q2) V1(q3) V1(q4) V1(q5) V1(q6)
    virtual void loadSolitaire(Cfg *);
};
class Race : public RaceB {
public:
    char pad1[0x6C - 0x68];
    Ctl *ctl;
    char pad2[0xCDC - 0x70];
    s32 fCDC;
    s32 state;
    char pad3[0xD6C - 0xCE4];
    s32 fD6C;
};
struct VEntry { short delta; short index; void *fn; };
struct Info { char pad[0x140]; };

extern s32 D_00621310;
extern Global *D_00622F4C;
extern "C" char RaceSolitaire__tf[];
extern "C" char RacePS2Base__tf[];

extern "C" void func_0010AF40(s32);
extern "C" void func_0010B9C8(Race *, s32) throw();
extern "C" s32 func_001D14E0(s32, Cfg *, s32);
extern "C" s32 func_001D1528(s32, Cfg *);
extern "C" s32 func_003470A0(s32 *);
extern "C" Ctl *func_003B7850(Info *);
extern "C" void RaceReplayInformation__structor_0(Info *, Cfg *);
extern "C" void RaceReplayInformation__structor_1(Info *, s32);
extern "C" Race *func_003DDA58(Info *, void *, s32);
extern "C" void func_003DDAB8(Info *, Race *, s32);
extern "C" void func_0044CA98(s32, s32, s32, s32);
extern "C" void func_0044CB10(void);
extern "C" void free(void *) throw();
extern "C" void *func_00578CB0(s32);
extern "C" Cfg *func_00578CF0(s32, s32);
extern "C" void *__dynamic_cast_2(void *from, void *to, s32 require_public, void *address, void *sub, void *subptr);

extern "C" s32 func_0010BBB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Info info;
    s32 ok = 0;
    func_0010AF40(0);
    Cfg *cfg = func_00578CF0(0x80, 0x61AC0);
    func_0044CA98(0x30000, 2, 6, 0xBC8000);
    s32 size = (D_00621310 + 0x3F) & ~0x3F;
    void *buf = func_00578CB0(size);
    s32 err;
    if (arg2 != 0) {
        err = func_001D14E0(arg0, cfg, D_00622F4C->f39DF8);
    } else {
        err = func_001D1528(arg0, cfg);
    }
    if (err == 0) {
        RaceReplayInformation__structor_0(&info, cfg);
        Ctl *ctl = func_003B7850(&info);
        Race *race = func_003DDA58(&info, buf, size);
        race->fD6C = 1;
        VEntry *vt;
        if (func_003470A0(&cfg->f1AA4) == 1 && race != 0
            && (vt = *(VEntry **)((char *)race + 0x64),
                __dynamic_cast_2(vt->fn, RaceSolitaire__tf, 0, (char *)race + vt->delta, RacePS2Base__tf, race) != 0)) {
            race->loadSolitaire(cfg);
        } else {
            race->load(cfg);
        }
        s32 mode = cfg->mode;
        s32 multi = 0;
        if (mode == 1 || mode == 3) multi = 1;
        ctl->fF0 = 1;
        race->fCDC = 1;
        race->ctl = ctl;
        func_0010B9C8(race, arg3);
        race->start(multi ? 3 : 2);
        s32 state = race->state;
        func_003DDAB8(&info, race, 0);
        if (ctl != 0) ctl->v0(3);
        free(buf);
        ok = state == 2;
        RaceReplayInformation__structor_1(&info, 2);
    }
    func_0044CB10();
    free(cfg);
    return ok ^ 1;
}
