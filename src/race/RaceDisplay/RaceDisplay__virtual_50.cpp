struct func_003A1030_Obj {
    char pad[0x1C];
    int state;
};

extern "C" int func_0039F0C0(func_003A1030_Obj *self, int dir);

extern "C" int RaceDisplay__virtual_50(func_003A1030_Obj *self, int delta) {
    switch (self->state) {
    case 1:
    case 2:
    case 17:
    case 18:
        return func_0039F0C0(self, delta >= 0 ? 1 : 2);
    case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
    case 11: case 12: case 13: case 14: case 15: case 16:
        return -1;
    default:
        return -1;
    }
}
