struct VEntry {
    short delta;
    short index;
    void *fn;
};

struct func_003E1C80_Mgr {
    char pad[0x64];
    VEntry *vtbl;
};

static inline int queryState(func_003E1C80_Mgr *m, void *buf) {
    VEntry *e = &m->vtbl[96];
    return ((int (*)(void *, void *))e->fn)((char *)m + e->delta, buf);
}

struct func_003E1C80_Rec {
    int count;
    int name;
};

struct func_003E1C80_Info {
    char pad0[0x88];
    func_003E1C80_Rec rec;
    char pad1[0xF4 - 0x90];
    char fx[4];
};

struct func_003E1C80_Obj {
    char pad0[0xC];
    VEntry *vtbl;
    char pad1[0x6C - 0x10];
    char name[0x564 - 0x6C];
    func_003E1C80_Mgr *mgr;
    char pad2[0x570 - 0x568];
    int x570;
    int x574;
};

static inline void notify(func_003E1C80_Obj *o, func_003E1C80_Info *info) {
    VEntry *e = &o->vtbl[7];
    ((void (*)(void *, void *))e->fn)((char *)o + e->delta, info);
}

extern "C" {
void func_00391DC8(float v);
void func_0042E478(int src, char *dst, int n);
void func_003B76F0(void *fx, int a, int b, int c);
void func_003E18D0(func_003E1C80_Obj *self, int n);
}

extern "C" void func_003E1C80(func_003E1C80_Obj *self, func_003E1C80_Info *info) {
    if (self->x574 == 0) {
        func_003E1C80_Rec *r = &info->rec;
        if (r->count > 0) {
            char buf[16];
            func_00391DC8(1.0f);
            self->x570 = r->count;
            self->x574 = 1;
            func_0042E478(r->name, self->name, 0x20);
            int v = queryState(self->mgr, buf);
            switch (v) {
            case 9:
            case 10:
                func_003B76F0(info->fx, 0x18, 11, 0);
                break;
            default:
                switch (self->x570) {
                case 1:
                case 2:
                    func_003B76F0(info->fx, 0x18, 0x15, 0);
                    break;
                case 3:
                    func_003B76F0(info->fx, 0x18, 0x16, 0);
                    break;
                case 4:
                case 5:
                    func_003B76F0(info->fx, 0x18, 0x17, 0);
                    break;
                }
                break;
            }
            func_003B76F0(info->fx, 0x16, 0, 0);
            notify(self, info);
            func_003E18D0(self, self->x570);
        }
    }
}
