typedef struct { char pad[0xB0]; int mode; } Obj;
int func_002B21D0(Obj *self, int key) {
    if (self->mode == 0) {
        switch (key) {
        case 0xFEE4:
        case 0xFEE6:
        case 0xFF51:
        case 0xFF96:
            return 1;
        }
    } else {
        switch (key) {
        case 0xFEE4:
        case 0xFEE5:
        case 0xFF52:
        case 0xFF97:
            return 1;
        }
    }
    return 0;
}
