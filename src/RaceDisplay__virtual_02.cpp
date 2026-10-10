struct func_0039F498_Car {
    char pad0[0xDC];
    int finished;
};

struct func_0039F498_Obj {
    int pad0;
    func_0039F498_Car *car;
    char pad8[0x20 - 0x8];
    unsigned int layout;
    char pad24[0x41 - 0x24];
    unsigned char always;
    unsigned char hidden;
    char pad43[0x70 - 0x43];
    char x70[0xB0 - 0x70];
    int originX;
    int originY;
    int padB8;
    float alpha;
    char padC0[0xD8 - 0xC0];
    int mutex;
    char padDC[0x1114 - 0xDC];
    float alpha1114;
    char pad1118[0x130C - 0x1118];
    float alpha130C;
    char pad1310[0x13A4 - 0x1310];
    float alpha13A4;
    char pad13A8[0x1690 - 0x13A8];
    float alpha1690;
    char pad1694[0x3EF8 - 0x1694];
    float alpha3EF8;
};

extern int D_006184F0;
extern char D_00623838[];

extern "C" void func_001056A0(void *buf);
extern "C" void func_004A4550(int a, int b);
extern "C" void func_004AB040(int n);
extern "C" void func_004A0670(void);
extern "C" void func_003AECE0(void);
extern "C" void func_004A5348(int n);
extern "C" void func_004A74B4(void *p);
extern "C" void func_004A7454(void);
extern "C" void func_0044E390(void *p, float x, float y);
extern "C" void func_0044DBC0(void *p, float x, float y);
extern "C" void func_0044E3B0(void *p, int x, int y);
extern "C" void func_0044D988(void *p);
extern "C" void func_00576788(void *mutex);
extern "C" void func_005767C0(void *mutex);
extern "C" void func_0039F718(func_0039F498_Obj *self, void *buf);
extern "C" void func_0039F878(func_0039F498_Obj *self, void *buf);
extern "C" void func_0039FA10(func_0039F498_Obj *self, void *buf);
extern "C" void func_0039FAD0(func_0039F498_Obj *self, void *buf);

extern "C" void func_0039F498(func_0039F498_Obj *self, void *buf) {
    if (!self->always && self->car->finished) return;
    if (self->hidden) return;
    func_001056A0(buf);
    func_004A4550(0, 1);
    func_004AB040(100);
    func_004AB040(15);
    func_004AB040(16);
    func_004AB040(13);
    func_004AB040(14);
    func_004A0670();
    func_003AECE0();
    func_004A5348(1);
    func_004A74B4(self->x70);
    func_004A5348(0);
    func_004A7454();
    float scale = 0.75f;
    if (D_006184F0 == 0) scale = 1.0f;
    func_0044E390(D_00623838, scale, 1.0f);
    func_0044DBC0(D_00623838, 1.0f, 1.0f);
    func_0044E3B0(D_00623838, self->originX, self->originY);
    float alpha = self->alpha;
    self->alpha13A4 = alpha;
    self->alpha1114 = alpha;
    self->alpha130C = alpha;
    self->alpha1690 = alpha;
    self->alpha3EF8 = alpha;
    func_00576788(&self->mutex);
    switch (self->layout) {
    case 0:
        func_0039F718(self, buf);
        break;
    case 2:
    case 3:
        func_0039F878(self, buf);
        break;
    case 4:
        func_0039FA10(self, buf);
        break;
    case 1:
        func_0039FAD0(self, buf);
        break;
    }
    func_005767C0(&self->mutex);
    func_0044E390(D_00623838, 1.0f, 1.0f);
    func_0044D988(D_00623838);
}
