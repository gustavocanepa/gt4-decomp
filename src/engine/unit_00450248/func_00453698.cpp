struct func_00453698_Elem {
    char pad0[0x1C];
    float f1C;
    float f20;
    char pad24[0x28 - 0x24];
    float f28;
    int i2C;
    char pad30[0x38 - 0x30];
};

struct func_00453698_Item {
    char pad[0x40];
};

struct func_00453698_Data {
    char pad0[0xC];
    char subC[0x38 - 0xC];
    int i38;
    char pad3C[0x48 - 0x3C];
    float f48[5];
    float f5C;
    float f60;
    float f64[4];
    char pad74[0x7C - 0x74];
    int i7C;
    int i80;
    float f84;
    char pad88[0x94 - 0x88];
    func_00453698_Elem elems[4];
    char pad174[0x174 - 0x174];
    int i174;
    char pad178[0x178 - 0x178];
    func_00453698_Item items[16];
    char pad578[0x578 - 0x578];
    char sub578[4];
};

struct func_00453698_Self {
    int pad0;
    func_00453698_Data *p;
};

extern "C" {
void func_00456850(float v);
void func_004A79D8(float v);
void func_004A7698(void *p);
void func_00454110(func_00453698_Elem *e, int odd);
void func_004A6100(float a, float b, float c, float d);
void func_004A60E0(float a, float b, float c, float d);
int func_004535A0(int odd, float a, float b);
void func_004541A0(func_00453698_Elem *e);
void func_004A1638(int n);
void func_004A7900(float a, float b, float c);
void func_004A79B0(float a);
int func_00453248(func_00453698_Data *p, int k);
void func_004A7890(float a, float b, float c);
int func_004A7CD0(void);
void func_004A19B0(int n);
void func_00453340(func_00453698_Data *p, int k);
void func_00454038(void *p);
}

extern "C" int func_00453698(func_00453698_Self *self, int req) {
    switch (req) {
    case 0:
        return self->p->i38;
    case 1:
    case 2:
    case 3:
    case 4:
        func_00456850(self->p->f48[req]);
        return 0;
    case 5:
        func_00456850(self->p->f5C);
        return 0;
    case 6:
        func_00456850(self->p->f64[0]);
        return 0;
    case 42:
    case 43:
    case 44:
    case 45:
        func_00456850(self->p->f64[req - 42]);
        return 0;
    case 7:
        return self->p->i7C;
    case 8:
        func_004A79D8(self->p->f60 * 0x1.CA5DC2p+5f);
        return 0;
    case 9:
        func_004A7698(self->p->sub578);
        return 0;
    case 11:
    case 12:
    case 13:
    case 14: {
        int k = req - 11;
        func_00453698_Elem *e = &self->p->elems[k];
        int odd = k & 1;
        func_00454110(e, odd);
        func_004A6100(0.0f, 0.0f, 0.0f, 0.0f);
        func_004A60E0(1.0f, 1.0f, 1.0f, e->f28);
        return func_004535A0(odd, e->f20, self->p->f84 * e->f1C) == 0;
    }
    case 15:
    case 16:
    case 17:
    case 18: {
        if (self->p->i174 == 0) return 1;
        int k = req - 15;
        float s = self->p->elems[k].f1C;
        func_004541A0(&self->p->elems[k]);
        func_004A1638(14);
        func_004A1638(19);
        func_004A7900(s, s, s);
        if (k & 1) func_004A79B0(180.0f);
        int r = func_00453248(self->p, k);
        if (r != 0 && self->p->elems[k].i2C != 0) func_004A7890(1.0f, 1.0f, -1.0f);
        return r == 0;
    }
    case 36:
    case 37:
    case 38:
    case 39: {
        int k = req - 36;
        int on = self->p->elems[k].i2C;
        int mode = func_004A7CD0();
        if (on) func_004A19B0(mode == 1 ? 2 : 1);
        func_00453340(self->p, k);
        if (on) func_004A19B0(mode);
        return 0;
    }
    case 46:
        func_00454038(self->p->subC);
        return 0;
    case 47:
        return self->p->i80;
    default:
        if ((unsigned int)(req - 20) < 16) func_004A7698(&self->p->items[req - 20]);
        return 0;
    }
}
