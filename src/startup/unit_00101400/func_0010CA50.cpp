/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct VEntry { short delta; short index; void *(*fn)(void); };
struct VEntryI { short delta; short index; void (*fn)(void *, s32); };

struct Buf {
    char pad0[0xC];
    s32 fC;
    char pad10[0x1AA4 - 0x10];
    s32 f1AA4;
};
struct VEntryB { short delta; short index; void (*fn)(void *, Buf *); };

struct Rec { char pad[0x1C]; Buf *u1C; };
struct Info { char b[0x140]; };
struct Pause { char b[0x1B0]; };

struct Course {
    char pad0[0x974];
    char *vtbl;
};

struct Run {
    char pad0[0x64];
    char *vtbl;
    char pad68[4];
    Course *u6C;
    char pad70[0xCE0 - 0x70];
    s32 fCE0;
    char padCE4[0xD6C - 0xCE4];
    s32 fD6C;
};

struct Self {
    char pad0[4];
    s32 f4;
    s32 f8;
    char padC[0xB4 - 0xC];
    char fB4[4];
};

struct Game {
    char pad0[0x38CB0];
    char f38CB0[0x39DF8 - 0x38CB0];
    s32 f39DF8;
    char pad39DFC[0x3B018 - 0x39DFC];
    char f3B018[4];
};

extern Game *D_00622F4C;
extern s32 RaceSolitaire__disable_logger_;
extern s32 D_00621310;
extern char RaceSolitaire__tf[];
extern char RaceBasic__tf[];

extern "C" void GranTurismo4__LoadingMode(const char *);
extern "C" s32 func_0010B290(const char *, s32);
extern "C" s32 func_001D14E0(char *, Buf *, s32);
extern "C" Rec *func_001D3A60(void);
extern "C" void func_001D3AD0(Rec *);
extern "C" s32 *func_001D3AF8(void);
extern "C" void func_0033CF38(s32);
extern "C" s32 func_003470A0(s32 *);
extern "C" void func_0038B850(Run *, Pause *);
extern "C" Course *func_003B7850(Info *);
extern "C" void PhotoPause__structor_0(Pause *, Run *);
extern "C" void PhotoPause__structor_1(Pause *, s32);
extern "C" void RaceReplayInformation__structor_0(Info *, Buf *);
extern "C" void RaceReplayInformation__structor_1(Info *, s32);
extern "C" Run *func_003DDA58(Info *, void *, s32);
extern "C" void func_003DDAB8(Info *, Run *, s32);
extern "C" void func_0042FC98(Self *, const char *);
extern "C" s32 func_004349A8(char *, char *);
extern "C" s32 func_00436640(char *);
extern "C" s32 func_00436740(char *);
extern "C" void func_0044CA98(int, int, int, int);
extern "C" void func_0044CB10(void);
extern "C" void free(void *) throw();
extern "C" void *func_00578CB0(s32);
extern "C" void *func_00578CF0(s32, s32);
extern "C" s32 func_0057F238(const char *, const char *);
extern "C" void *__dynamic_cast_2(void *(*)(void), char *, s32, void *, char *, void *);

struct Lazy {
    Buf *p;
    Lazy() { p = 0; }
    ~Lazy() { free(p); }
};

#define GET() { b = buf.p; if (b == 0) { b = (Buf *)func_00578CF0(0x80, 0x31AC0); buf.p = b; } }

extern "C" void func_0010CA50(Self *self) {
    Lazy buf;
    Buf *b;
    func_0033CF38(1);
    RaceSolitaire__disable_logger_ = 1;
    func_00436640(D_00622F4C->f38CB0);
    func_001D3AD0(func_001D3A60());
    Rec *rec = func_001D3A60();
    GET()
    rec->u1C = b;
    func_0042FC98(self, "ReplayTheaterRoot");
    func_0010B290("labomode", 0);
    s32 n = *func_001D3AF8();
    s32 list = func_0057F238(self->fB4, "list") == 0;
    s32 cont = list;
    if (n != 0) {
        s32 i = 0;
        do {
            if (list) {
                char path[0x40];
                s32 cnt = func_004349A8(D_00622F4C->f3B018, path);
                if (cnt == 0) {
                    break;
                }
                GET()
                s32 r = func_001D14E0(path, b, D_00622F4C->f39DF8);
                if (r < 0) {
                    break;
                }
                if (r > 0) {
                    i++;
                    if (i >= cnt) {
                        break;
                    }
                }
            }
            GET()
            s32 kind = b->fC;
            s32 flag = 0;
            if (kind == 1 || kind == 3) {
                flag = 1;
            }
            func_0044CA98(0x30000, 2, 6, 0xBC8000);
            s32 size = (D_00621310 + 0x3F) & ~0x3F;
            void *mem = func_00578CB0(size);
            Info info;
            Pause pp;
            GET()
            RaceReplayInformation__structor_0(&info, b);
            Course *course = func_003B7850(&info);
            Run *run = func_003DDA58(&info, mem, size);
            run->fD6C = 1;
            GET()
            if (func_003470A0(&b->f1AA4) == 1 && run != 0
                && __dynamic_cast_2(((VEntry *)run->vtbl)->fn, RaceSolitaire__tf, 0,
                                 (char *)run + ((VEntry *)run->vtbl)->delta, RaceBasic__tf, run) != 0) {
                GET()
                VEntryB *e = (VEntryB *)(run->vtbl + 0x4F0);
                e->fn((char *)run + e->delta, b);
            } else {
                GET()
                VEntryB *e = (VEntryB *)(run->vtbl + 0x1C8);
                e->fn((char *)run + e->delta, b);
            }
            PhotoPause__structor_0(&pp, run);
            func_0038B850(run, &pp);
            run->u6C = course;
            {
                VEntryI *e = (VEntryI *)(run->vtbl + 0x328);
                e->fn((char *)run + e->delta, flag ? 3 : 2);
            }
            if (run->fCE0 == 2) {
                cont = 0;
            }
            func_003DDAB8(&info, run, 0);
            if (course) {
                VEntryI *e = (VEntryI *)(course->vtbl + 8);
                e->fn((char *)course + e->delta, 3);
            }
            free(mem);
            PhotoPause__structor_1(&pp, 2);
            RaceReplayInformation__structor_1(&info, 2);
            func_0044CB10();
        } while (cont);
    } else {
        if (func_00436740(D_00622F4C->f38CB0)) {
            GranTurismo4__LoadingMode("default");
        }
        self->f4 = self->f8;
        self->f8 = 1;
    }
    RaceSolitaire__disable_logger_ = 0;
    func_0033CF38(0);
}
