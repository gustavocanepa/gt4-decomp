/* RaceDisplay::init_display_switch_by_run_mode (GT HD name) */
struct RaceDisplay {
    char pad0[0x43];
    unsigned char x43;
    char pad1[0x58 - 0x44];
    int x58;
    int x5c;
    int x60;
};

extern "C" void RaceDisplay__virtual_32(RaceDisplay *self, unsigned int mode) {
    switch (mode) {
    case 0:
    case 1:
        self->x58 = self->x5c;
        break;
    case 2:
        {
            int v = 0;
            if (self->x43 == 0)
                v = self->x60;
            self->x58 = v;
        }
        break;
    case 3:
        {
            int v = 0;
            if (self->x43 == 0)
                v = self->x60 & ~4;
            self->x58 = v;
        }
        break;
    case 4:
    default:
        if (self->x43 == 0)
            self->x58 = 0x80;
        else
            self->x58 = 0x80;
        break;
    }
}
