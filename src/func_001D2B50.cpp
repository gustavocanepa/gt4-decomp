struct func_001D2B50_Obj {
    char pad[0x6A0];
    int mode;
};

extern "C" int func_001D2B50(func_001D2B50_Obj *self, int c) {
    switch (self->mode) {
    case 1:
        return c > 0;
    case 2:
        return c == 'R' || c == 'B' || c == 'D';
    case 3:
        return c == 'R' || c == 'D';
    case 4:
        return c == 'B';
    case 6:
        return c == 'F';
    case 7:
        return c == 'P';
    case 8:
        return 1;
    default:
        return 0;
    }
}
