struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

struct VObj {
    VEntry *vtbl;
};

static inline int vcall(VObj *o, int i) {
    VEntry *e = &o->vtbl[i];
    return e->fn((char *)o + e->delta);
}

struct func_001D2CA0_Obj {
    char pad0[0x30];
    VObj *dev;
    char pad1[0x674 - 0x34];
    int x674;
    char pad2[0x684 - 0x678];
    int x684;
    int x688;
    int x68c;
    int x690;
    int pad694[2];
    int state;
    char pad3[0x6C8 - 0x6A0];
    int x6c8;
};

extern "C" {
int func_001D28A0(func_001D2CA0_Obj *self);
void func_001D2968(func_001D2CA0_Obj *self);
void func_00578B10(int ticks);
void func_001D2E18(func_001D2CA0_Obj *self);
void func_001D2EA8(func_001D2CA0_Obj *self);
void func_001D3150(func_001D2CA0_Obj *self);
void func_001D35B8(func_001D2CA0_Obj *self);
}

extern "C" void func_001D2CA0(func_001D2CA0_Obj *self) {
    if (func_001D28A0(self)) {
        func_001D2968(self);
        self->x690 = vcall(self->dev, 4);
        return func_00578B10(0x27100);
    }
    self->x68c = vcall(self->dev, 3);
    if (self->x68c == 0) {
        func_001D2968(self);
        return func_00578B10(0x27100);
    }
    switch (self->state) {
    case 0:
        if (vcall(self->dev, 4)) {
            self->x690 = 1;
            self->state++;
            self->x6c8 = 0;
            self->x674 = 0;
        } else {
            self->x690 = 0;
            self->x674 = 0;
            self->x684 = 0;
            self->state = 6;
        }
        break;
    case 1:
        func_001D2E18(self);
        break;
    case 2:
        func_001D2EA8(self);
        break;
    case 3:
        func_001D3150(self);
        break;
    case 4:
        self->state++;
        break;
    case 5:
        func_001D35B8(self);
        break;
    case 6:
        break;
    }
}
