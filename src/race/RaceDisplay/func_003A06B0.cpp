struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

static inline int vcall(VEntry *vtbl, void *o, int k) {
    VEntry *e = &vtbl[k];
    return e->fn((char *)o + e->delta);
}

struct VEntryV {
    short delta;
    short index;
    void (*fn)(void *);
};

static inline void vcall_void(VEntryV *vtbl, void *o, int k) {
    VEntryV *e = &vtbl[k];
    e->fn((char *)o + e->delta);
}

struct func_003A06B0_Event {
    int id;
    VEntry *vtbl;
    int kind;
    int pad;
};

struct func_003A06B0_Disp {
    char pad0[0x20];
    unsigned int color;
};

struct func_003A06B0_Self {
    VEntryV *vtbl;
    char pad4[0x2E - 0x4];
    signed char id2E;
    signed char id2F;
    char pad30[0x17BC - 0x30];
    func_003A06B0_Disp disp;
    char pad17E0[0x228C - 0x17E0];
    func_003A06B0_Disp msg;
    char pad22B0[0x22C0 - 0x22B0];
    char osc[4];
};

struct func_003A06B0_Table {
    int pad[2];
    char **entries;
};

struct func_003A06B0_Sub {
    char pad[0x800];
    unsigned char counts[1];
    int count(int t) { return counts[t]; }
};

struct func_003A06B0_Info {
    char pad0[0x60];
    func_003A06B0_Table *table;
    char pad64[0xFC - 0x64];
    func_003A06B0_Sub sub;
};

extern char **DisplayRText__rtext_ptrs_;
extern char D_00621515;
extern char D_006A0718[];

extern "C" {
void RaceDisplayInformationEvent__structor_0(func_003A06B0_Event *ev);
int func_003A3248(func_003A06B0_Event *ev, func_003A06B0_Info *info, int i);
int func_0057DA20(char *buf, const char *fmt, ...);
void func_003A0A20(func_003A06B0_Self *self, int id);
void Oscillator__setCount(void *osc, int a, int b);
void RaceMessageDisplay__setMessage(func_003A06B0_Disp *d, char *text, float t, float u);
char *func_005A6AB0(char *dst, const char *src, unsigned int n);
void func_003A5268(func_003A06B0_Disp *d, char *name, int a);
void RaceEventDisplay__addEvent(func_003A06B0_Disp *d, char *text, float a, float b, float c, float e);
}

extern "C" void func_003A06B0(func_003A06B0_Self *self, func_003A06B0_Info *info) {
    func_003A06B0_Event ev;
    char buf[0x100];
    int i;
    RaceDisplayInformationEvent__structor_0(&ev);
    for (i = 0; i < info->sub.count(vcall(ev.vtbl, &ev, 1)); i++) {
        ev.id = -1;
        if (func_003A3248(&ev, info, i) == 0) return;
        int id = ev.id;
        char *name = info->table->entries[id] + 0x348C;
        buf[0] = 0;
        switch (ev.kind) {
        case 1:
            func_0057DA20(buf, DisplayRText__rtext_ptrs_[9], name, id);
            break;
        case 2:
            func_003A0A20(self, id);
            break;
        case 3:
        case 4:
        case 5:
            break;
        case 6:
            if (id < 0 || (id == self->id2E && id == self->id2F)) {
                vcall_void(self->vtbl, self, 40);
                D_00621515 = 1;
            }
            break;
        case 7:
            if (id == self->id2F) {
                func_003A06B0_Disp *m = &self->msg;
                m->color = 0x80FF8080;
                Oscillator__setCount(self->osc, 0, 0);
                RaceMessageDisplay__setMessage(m, DisplayRText__rtext_ptrs_[0x43], 2.0f, 0.0f);
                D_00621515 = 1;
            }
            return;
        case 8:
        case 9:
            return;
        case 10:
            func_005A6AB0(buf, DisplayRText__rtext_ptrs_[3], 0xFF);
            buf[0xFF] = 0;
            break;
        case 11:
        default:
            return;
        }
        func_003A06B0_Disp *d = &self->disp;
        func_003A5268(d, D_006A0718, 1);
        d->color = 0x80C8C8C8;
        RaceEventDisplay__addEvent(d, buf, 3.0f, 0.0f, 0.0f, 0.0f);
    }
}
