extern char *D_00622F4C;

struct RaceDisplay {
    char pad0[0x20];
    unsigned int x20;
    int pad24;
    int x28;
    int pad2c;
    int x30;
    int pad34;
    int x38;
};

extern "C" void func_0039BCA8(RaceDisplay *self) {
    self->x30 = (self->x30 & 0xFFFFFF) | (*(unsigned char *)(D_00622F4C + 0x39DF4) << 24);
    self->x30 = (self->x30 & 0xFFFF00FF) | 0x100;
    self->x30 = (self->x30 & 0xFF00FFFF) | 0x10000;
    self->x28 = -10;
    switch (self->x20) {
    case 0:
    case 1:
    case 4:
        break;
    case 2:
    case 3:
        self->x38 &= 0xFF00FFFF;
        break;
    }
}
