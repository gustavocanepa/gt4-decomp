extern char D_006A0DE0[], D_006A0FD8[], D_006A11F8[], D_006A1208[], D_006A1218[], D_006A08F0[],
    D_006A0838[], D_006A09A8[], D_006A0BA0[], D_006A0D50[];

struct RaceDisplay {
    char pad0[0x38];
    unsigned char x38;
    char pad1[0x64 - 0x39];
    int x64;
    int pad68;
    float x6c;
    char pad2[0x16A0 - 0x70];
    char layer0[0x1C];
    char layer1[0x1C];
};

extern "C" {
void func_003A2630(RaceDisplay *self, const char *layout);
void func_003A1970(RaceDisplay *self, int mode);
void func_003AECB0(void *layer, const char *anim);
}

extern "C" void RaceDisplay__virtual_33(RaceDisplay *self, int kind, unsigned int sub, int mode) {
    switch (kind) {
    case 8:
        func_003A2630(self, D_006A0DE0);
        func_003A1970(self, 1);
        self->x6c = 240.0f;
        func_003AECB0(self->layer0, D_006A11F8);
        return func_003AECB0(self->layer1, D_006A1208);
    case 9:
        func_003A2630(self, D_006A0FD8);
        func_003A1970(self, 3);
        func_003AECB0(self->layer0, D_006A11F8);
        return func_003AECB0(self->layer1, D_006A1208);
    }
    int alt = 0;
    if (kind == 2 || self->x38 != 0)
        alt = 1;
    const char *layout;
    if (alt) {
        func_003AECB0(self->layer0, D_006A1218);
        func_003AECB0(self->layer1, D_006A11F8);
        layout = D_006A08F0;
    } else {
        func_003AECB0(self->layer0, D_006A11F8);
        func_003AECB0(self->layer1, D_006A1208);
        layout = D_006A0838;
    }
    switch (sub) {
    case 0:
        func_003A2630(self, D_006A09A8);
        func_003A2630(self, layout);
        return func_003A1970(self, mode);
    case 2:
    case 3:
        func_003A2630(self, D_006A09A8);
        func_003A2630(self, layout);
        if (self->x64)
            return func_003A1970(self, mode);
        break;
    case 1:
        func_003A2630(self, D_006A0BA0);
        func_003A1970(self, mode);
        return func_003AECB0(self->layer0, D_006A1218);
    case 4:
        return func_003A2630(self, D_006A0D50);
    }
}
