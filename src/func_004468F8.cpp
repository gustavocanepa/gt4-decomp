typedef long long s64;

struct func_004468F8_Obj {
    s64 r[0x168 / 8];
    unsigned char dirty;
};

extern "C" {
void func_00443240(func_004468F8_Obj *self);
void func_00444A88(func_004468F8_Obj *self);
void func_00444B88(func_004468F8_Obj *self);
void func_00444C08(func_004468F8_Obj *self);
void func_00444CA0(func_004468F8_Obj *self);
void func_00444D38(func_004468F8_Obj *self);
void func_00444DD0(func_004468F8_Obj *self);
void func_00444FE0(func_004468F8_Obj *self);
void func_004450D8(func_004468F8_Obj *self);
void func_004451A0(func_004468F8_Obj *self);
void func_00445230(func_004468F8_Obj *self);
}

extern "C" void func_004468F8(func_004468F8_Obj *self, s64 reg) {
    switch ((int)(reg >> 32)) {
    case 1:
        self->r[0x20 / 8] = reg;
        break;
    case 2:
        self->r[0x28 / 8] = reg;
        return func_00444C08(self);
    case 3:
        self->r[0x50 / 8] = reg;
        return func_00444DD0(self);
    case 4:
        self->r[0xE0 / 8] = reg;
        return func_004450D8(self);
    case 5:
        self->r[0xE8 / 8] = reg;
        return func_004451A0(self);
    case 6:
        self->r[0x30 / 8] = reg;
        break;
    case 7:
        self->r[0x80 / 8] = reg;
        return func_00444CA0(self);
    case 8:
        self->r[0x78 / 8] = reg;
        break;
    case 9:
        self->r[0x70 / 8] = reg;
        break;
    case 10:
        self->r[0x40 / 8] = reg;
        return func_00444B88(self);
    case 11:
        self->r[0x48 / 8] = reg;
        func_00444A88(self);
        return func_00443240(self);
    case 12:
        self->r[0x38 / 8] = reg;
        break;
    case 13:
        self->r[0xA8 / 8] = reg;
        break;
    case 14:
        self->r[0xB0 / 8] = reg;
        return func_00444D38(self);
    case 15:
        self->r[0x88 / 8] = reg;
        break;
    case 16:
        self->r[0x90 / 8] = reg;
        break;
    case 17:
        self->r[0x98 / 8] = reg;
        break;
    case 18:
        self->r[0xA0 / 8] = reg;
        break;
    case 19:
        self->r[0xD8 / 8] = reg;
        break;
    case 20:
        self->r[0xD0 / 8] = reg;
        break;
    case 21:
        self->r[0xC0 / 8] = reg;
        break;
    case 22:
        self->r[0xB8 / 8] = reg;
        break;
    case 23:
        self->r[0xC8 / 8] = reg;
        break;
    case 24:
        self->r[0x58 / 8] = reg;
        return func_00444FE0(self);
    case 25:
        self->r[0x60 / 8] = reg;
        break;
    case 26:
        self->r[0x68 / 8] = reg;
        break;
    case 29:
        self->r[0xF0 / 8] = reg;
        break;
    case 27:
        self->r[0xF8 / 8] = reg;
        return func_00445230(self);
    case 30:
        self->r[0x100 / 8] = reg;
        break;
    case 28:
        self->r[0x108 / 8] = reg;
        break;
    case 31:
        self->dirty = 1;
        break;
    }
}
