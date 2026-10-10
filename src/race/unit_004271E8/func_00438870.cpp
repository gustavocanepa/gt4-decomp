struct func_00438870_State {
    unsigned char flags;
    unsigned char mode;
    unsigned char count;
    unsigned char pad3;
    unsigned short value;
    unsigned char pad6;
    unsigned char held;
    short a;
    short b;
    short d;
    short c;
};

struct func_00438870_Obj {
    func_00438870_State *state;
    unsigned int buttons;
    char pad8[0x18 - 0x8];
    unsigned int misc;
    char pad1C[0x20 - 0x1C];
    unsigned int extra;
};

extern "C" void func_00438870(func_00438870_Obj *self, int type, int pressed) {
    func_00438870_State *s;
    int delta;
    int step;
    if (!pressed) return;
    s = self->state;
    delta = 2;
    step = 1;
    switch (type) {
    case -1:
        break;
    case 1:
        delta = -2;
    case 0:
        s->flags &= ~1;
        s->mode = 0;
        s->value += delta;
        break;
    case 2:
        step = -1;
    case 3:
        s->count += step;
        break;
    case 4:
        s->a = 1;
        s->flags &= ~2;
        break;
    case 5:
        s->b = 1;
        s->flags &= ~4;
        break;
    case 6:
        s->c = 1;
        s->flags &= ~0x10;
        break;
    case 7:
        s->d = 1;
        s->flags &= ~8;
        break;
    case 8:
        s->held = 1;
        break;
    case 9:
        self->buttons |= 2;
        break;
    case 10:
        self->buttons |= 1;
        break;
    case 11:
        self->buttons |= 0x10000;
        break;
    case 12:
        self->buttons |= 0x20000;
        break;
    case 13:
        self->buttons |= 0x4000;
        break;
    case 14:
        self->buttons |= 0x8000;
        break;
    case 15:
        self->extra |= 1;
        break;
    case 16:
        self->extra |= 2;
        break;
    case 17:
        self->misc |= 0x40;
        break;
    }
}
