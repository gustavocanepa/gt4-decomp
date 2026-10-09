typedef struct { char pad[0xB0]; int mode; } Obj;
int func_002B2270(Obj *self, int key) {
    if (self->mode == 0) {
        switch (key) {
        case 0xFEE5:
        case 0xFEE7:
        case 0xFF53:
        case 0xFF98:
            return 1;
        }
    } else {
        switch (key) {
        case 0xFEE6:
        case 0xFEE7:
        case 0xFF54:
        case 0xFF99:
            return 1;
        }
    }
    return 0;
}
