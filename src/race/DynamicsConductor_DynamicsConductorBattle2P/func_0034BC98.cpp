struct func_0034BC98_Self {
    char pad0[0x128];
    unsigned char mode;
    unsigned char sub;
    unsigned char level;
    unsigned char count;
};

extern unsigned char D_00620308;
extern unsigned char D_00620309;
extern float D_0062030C;
extern unsigned char D_00620310;
extern float D_00620314;
extern unsigned char D_00620318;

extern "C" void func_00355978(func_0034BC98_Self *self);

extern "C" unsigned char func_0034BC98(func_0034BC98_Self *self, unsigned char *kind, unsigned char *flag, float *value, float *weight) {
    *value = 0.0f;
    *weight = 0.0f;
    switch (self->mode) {
    case 0:
    case 3:
    case 4:
        *kind = 0;
        *flag = 1;
        break;
    case 1:
        *kind = 1;
        *flag = 0;
        break;
    case 2:
        {
        int sub = self->sub;
        *value = (float)self->level * 0x1.47AE14p-7f;
        *flag = 1;
        switch (sub) {
        case 0:
            *kind = 2;
            *flag = 0;
            break;
        case 2:
            *kind = 4;
            if (self->level >= 50) *value = 1.0f;
            {
                int c = self->count;
                int n = 8;
                if (c != 0) n = c;
                *weight = (float)(n * 10) * 0x1.399998p+3f;
            }
            break;
        case 3:
            *kind = 5;
            *value *= 0x1.70A3DAp-2f;
            {
                float r = (float)D_00620308 / 100.0f;
                float w = (float)(D_00620309 * 10) * 0x1.399998p+3f;
                *value *= r;
                D_0062030C = (float)D_00620310 / 100.0f;
                D_00620314 = (float)D_00620318 / 100.0f;
                *weight = w;
            }
            break;
        case 4:
            *kind = 6;
            if (*value != 0.0f) *value = 1.0f / (*value * 100.0f * 0x1.1DF468p-6f);
            {
                int c = self->count;
                int n = 15;
                if (c != 0) n = c;
                *weight = (float)(n * 10) * 0x1.399998p+3f;
            }
            break;
        case 5:
            *kind = 7;
            func_00355978(self);
            break;
        case 7:
            *kind = 8;
            break;
        case 6:
            *kind = 9;
            *flag = 0;
            break;
        case 8:
            *kind = 10;
            break;
        case 1:
        default:
            *kind = 3;
            break;
        }
        }
        break;
    }
    return *kind;
}
