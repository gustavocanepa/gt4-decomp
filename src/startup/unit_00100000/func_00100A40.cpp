struct func_00100A40_Vec {
    float x, y, z;
};

struct func_00100A40_Obj {
    char pad0[0x6C];
    char x6c[0x9C - 0x6C];
    int mode;
    int pending;
};

extern char D_006184D0[];
extern func_00100A40_Vec D_00617A90;

extern "C" {
void func_00106710(void *p);
void func_001063A8(void *p);
void func_00106DA8(void *p, int a, int b, int c, int d);
void func_004A2980(int a);
void func_004A3040(float x, float y, float z, float w);
void func_001009F0(void);
void func_00574EE8(void *p);
}

extern "C" void func_00100A40(func_00100A40_Obj *self) {
    if (self->pending) {
        switch (self->mode) {
        case 1:
            func_00106710(D_006184D0);
            break;
        case 2:
            func_001063A8(D_006184D0);
            break;
        case 3:
            func_00106DA8(D_006184D0, 1, 2, -1, -1);
            break;
        case 4:
            func_00106DA8(D_006184D0, 2, 0x50, -1, -1);
            break;
        case 5:
            func_00106DA8(D_006184D0, 2, 0x51, -1, -1);
            break;
        }
        func_004A2980(-1);
        func_004A3040(D_00617A90.x, D_00617A90.y, D_00617A90.z, 0.0f);
        func_001009F0();
        func_00574EE8(self->x6c);
        self->pending = 0;
    }
}
