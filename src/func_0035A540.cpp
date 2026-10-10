struct func_0035A540_Obj {
    char pad0[0x654];
    float f654;
    char pad1[0x768 - 0x658];
    float f768;
    float f76c;
    float f770;
    char pad2[0x778 - 0x774];
    float f778[4];
};

extern "C" float func_0035A498(func_0035A540_Obj *self, int which);

extern "C" float func_0035A540(func_0035A540_Obj *self, int k) {
    if (k < 4)
        return self->f778[k];
    switch (k) {
    case 4:
        return func_0035A498(self, 0);
    case 5:
        return func_0035A498(self, 1);
    case 7:
        return self->f654 / 0x1.3999980000000p+3f;
    case 8:
        return self->f768;
    case 9:
        return self->f76c;
    case 10:
        return self->f770;
    default:
        return 0.0f;
    }
}
