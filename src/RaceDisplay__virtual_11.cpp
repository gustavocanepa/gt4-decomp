/* RaceDisplay::setViewMode (GT HD name) */
struct RaceDisplay {
    char pad0[0x24];
    int x24;
    int viewMode;
    int pad2c;
    int x30;
};

extern "C" int func_003A1628(RaceDisplay *self);

extern "C" void RaceDisplay__virtual_11(RaceDisplay *self, int mode) {
    if (self->viewMode == mode)
        return;
    self->viewMode = mode;
    switch (mode) {
    case 0:
    case 6:
        self->x24 = 0;
        break;
    case -1:
        if (func_003A1628(self))
            return;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    default:
        self->x24 = 1;
        break;
    }
    self->x30 = (self->x30 & 0xFFFF00FF) | 0x100;
}
