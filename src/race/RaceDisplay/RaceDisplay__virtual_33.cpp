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
void RaceDisplay__init_display_objects(RaceDisplay *self, const char *layout);
void RaceDisplay__init_panel(RaceDisplay *self, int mode);
void RaceDisplayObjectBase__selectTexture(void *layer, const char *anim);
}

extern "C" void RaceDisplay__virtual_33(RaceDisplay *self, int kind, unsigned int sub, int mode) {
    switch (kind) {
    case 8:
        RaceDisplay__init_display_objects(self, D_006A0DE0);
        RaceDisplay__init_panel(self, 1);
        self->x6c = 240.0f;
        RaceDisplayObjectBase__selectTexture(self->layer0, D_006A11F8);
        return RaceDisplayObjectBase__selectTexture(self->layer1, D_006A1208);
    case 9:
        RaceDisplay__init_display_objects(self, D_006A0FD8);
        RaceDisplay__init_panel(self, 3);
        RaceDisplayObjectBase__selectTexture(self->layer0, D_006A11F8);
        return RaceDisplayObjectBase__selectTexture(self->layer1, D_006A1208);
    }
    int alt = 0;
    if (kind == 2 || self->x38 != 0)
        alt = 1;
    const char *layout;
    if (alt) {
        RaceDisplayObjectBase__selectTexture(self->layer0, D_006A1218);
        RaceDisplayObjectBase__selectTexture(self->layer1, D_006A11F8);
        layout = D_006A08F0;
    } else {
        RaceDisplayObjectBase__selectTexture(self->layer0, D_006A11F8);
        RaceDisplayObjectBase__selectTexture(self->layer1, D_006A1208);
        layout = D_006A0838;
    }
    switch (sub) {
    case 0:
        RaceDisplay__init_display_objects(self, D_006A09A8);
        RaceDisplay__init_display_objects(self, layout);
        return RaceDisplay__init_panel(self, mode);
    case 2:
    case 3:
        RaceDisplay__init_display_objects(self, D_006A09A8);
        RaceDisplay__init_display_objects(self, layout);
        if (self->x64)
            return RaceDisplay__init_panel(self, mode);
        break;
    case 1:
        RaceDisplay__init_display_objects(self, D_006A0BA0);
        RaceDisplay__init_panel(self, mode);
        return RaceDisplayObjectBase__selectTexture(self->layer0, D_006A1218);
    case 4:
        return RaceDisplay__init_display_objects(self, D_006A0D50);
    }
}
