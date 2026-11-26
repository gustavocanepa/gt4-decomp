/* compiler: ee-gcc2.96-nogcse */
/*
 * func_00393D20 - CarIconMaker: render one car icon (inferred).
 *
 * Called twice per car by CarIconMaker::render (a 0x80x0x40 large icon and a 0x40x0x20
 * small one). Draws an 8-band grey gradient into a background buffer, renders the car
 * model (virtual methods of the model at entry+0x2880) into a work buffer with a camera
 * fitted to the car's dimensions - orthographic for the small icon, perspective for the
 * large one (sphere fit of the car's half extents and an acos for the view angle) - then
 * composites into `dst`, the large icon through an 8-direction blur ring.
 */
typedef int s32;
typedef short s16;
typedef float f32;

struct GSBuffer {
    char pad0[8];
    s32 width;
    char padC[4];
    s32 x, y, w, h;
    char pad20[0x20];
};
struct Texture { char pad[0x30]; };
struct ShowRoomCar { char pad[0x10]; };

/* The car model: virtual slots used here are 2, 7, 20, 22 and 24. */
struct Model {
    char pad0[8];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(s32);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20(Texture *);
    virtual void slot21();
    virtual void slot22(s32, f32);
    virtual void slot23();
    virtual void slot24(s32, s32, s32, f32);
};
struct Light { char pad0[0x58]; f32 f58; };
struct L2 { char pad0[0x80]; Light *f80; };
struct L1 { char pad0[4]; L2 *f4; };
struct Scene { char pad0[8]; L1 *f8; };
struct Entry {
    char pad0[0x18];
    Scene *scene;
    char pad1c[4];
    char car[0x2880 - 0x20];
    Model *model;
};
struct List { char pad0[8]; Entry **items; };
struct Inner { char pad0[0x60]; List *f60; };
struct Obj { char pad0[0x74]; Inner *f74; };

extern "C" {
void func_00105280(void *, s32);
s32 func_001052E0(void *, s32, s32, s32);
void func_00105338(void *, void *, s32);
void func_001056A0(void *);
void func_00105708(void *);
void func_00105728(void *);
s32 func_00105818(void *);
void GSBuffer__getTexture(void *, void *);
void func_00343490(char *);
f32 func_00344C88(void *, s32);
void ShowRoomCar__structor_0(void *);
void ShowRoomCar__structor_1(void *, s32);
void func_00364868(void *, void *, char *);
f32 func_00364BB0(void *, s32, f32, f32);
f32 func_00393CF0(f32);
void func_00394A10(Obj *);
void func_003F36B8(void *);
void func_003F36C8(void *);
s32 func_00445D90(void *);
s32 func_00445DC0(void *);
s32 func_00445DF0(void *);
void func_004523E8(f32, f32, f32, f32);
void func_00452408(f32);
void func_004567D0(s32);
void func_004A1638(s32);
void func_004A26F0(s32);
void func_004A2750(s32, f32);
void func_004A2858(s32, f32);
void func_004A28B8(s32, s32);
void func_004A2980(s32);
void func_004A29A8(s32);
void func_004A2D20(s32, s32, s32, s32);
void func_004A3040(f32, f32, f32, f32);
void func_004A3078(s32);
void func_004A3088(f32);
void func_004A3230(s32);
void func_004A40B0(f32, f32);
void func_004A4550(s32, s32);
void func_004A4910(void);
void RaceEntryCar__update(s32);
void func_004A53F8(void);
void func_004A5400(void);
void func_004A59B8(f32, f32, f32, f32, f32, f32, f32);
void func_004A5A90(f32, f32, f32, f32, f32, f32);
void func_004A6140(s32, s32, s32, s32);
void func_004A6668(f32, f32, f32, f32, f32, f32, f32, f32);
void func_004A6788(f32, f32, f32, f32, f32, f32, f32, f32);
void func_004A6F10(s32, s32);
void func_004A7454(void);
void func_004A7844(f32, f32, f32);
void func_004A7890(f32, f32, f32);
void func_004A7988(f32);
void func_004A79B0(f32);
void func_004AA168(s32);
void func_004AA1D8(f32, f32, f32, f32);
void func_004AB040(s32);
f32 func_0057D380(f32);
void func_0057D8A0(f32 *, f32 *, f32);
}

static inline f32 sqrtf_(f32 x) { f32 r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" void func_00393D20(Obj *self, s32 index, GSBuffer *dst, s32 w, s32 h, s32 small) {
    ShowRoomCar car;
    char name[0x20];
    func_004A2980(-1);
    Entry *e = self->f74->f60->items[index];
    Model *model = e->model;
    ShowRoomCar__structor_0(&car);
    func_00343490(name);
    func_00364868(&car, e->car, name);
    Scene *scene = e->scene;
    f32 sx = (f32)func_00445D90(e->car) * 0x1.0624dcp-10f;
    f32 sy = (f32)func_00445DC0(e->car) * 0x1.0624dcp-10f;
    f32 sz = (f32)func_00445DF0(e->car) * 0x1.0624dcp-10f;
    func_003F36B8(scene);
    func_003F36C8(scene);
    f32 base = func_00344C88(scene, 0);
    f32 height = base - func_00364BB0(&car, 0, 0.0f, 0.0f);

    GSBuffer gradBuf;
    GSBuffer *grad = &gradBuf;
    func_001052E0(grad, 0, 0x80, 0x80);
    func_001056A0(grad);
    func_004A3040(0.0f, 0.0f, 0.0f, 1.0f);
    func_004A3230(1);
    func_004AB040(4);
    func_004AB040(6);
    func_004AB040(5);
    func_004AB040(8);
    func_004AB040(3);
    for (s32 i = 0; i < 8; i++) {
        f32 g = (f32)(7 - i) / 7.0f;
        func_004AA1D8(g, g, g, 1.0f);
        func_004A6140(0, i * 8, 0x80, i * 8 + 8);
    }
    Texture texBuf;
    Texture *tex = &texBuf;
    GSBuffer__getTexture(grad, tex);

    GSBuffer workBuf;
    GSBuffer *work = &workBuf;
    func_001052E0(work, 0, w * 2, h * 2);
    func_001056A0(work);
    GSBuffer depthBuf;
    GSBuffer *depth = &depthBuf;
    func_00105338(depth, work, 0x31);
    func_00105708(depth);
    func_004A3040(0.0f, 0.0f, 0.0f, 1.0f);
    func_004A3088(1.0f);
    func_004A29A8(1);
    func_004A3230(3);
    s32 bw = workBuf.width;
    s32 bh = func_00105818(work);
    func_004A2D20(0, 0, bw, bh);
    f32 cosv;
    if (small) {
        f32 fw = (f32)bw;
        RaceEntryCar__update(1);
        func_004A7454();
        f32 fh = (f32)bh;
        func_004A5A90((f32)-bw * 0.5f, fw * 0.5f, (f32)-bh * 0.5f, fh * 0.5f, 0.0f, 20.0f);
        RaceEntryCar__update(0);
        func_004A7454();
        f32 aspect = fw / fh;
        if (sx / sy < aspect)
            cosv = fh / sy * 0x1.b33332p-1f;
        else
            cosv = fw / sx * 0x1.b33332p-1f;
        func_004A7890(cosv, cosv, 1.0f);
        func_004A7844(0.0f, height - sy * 0.5f, -10.0f);
        func_004A79B0(90.0f);
    } else {
        f32 fw = (f32)bw;
        RaceEntryCar__update(1);
        func_004A7454();
        f32 fh0 = (f32)h;
        f32 angle = 158.0f;
        f32 t0 = func_0057D380(0x1.418934p-3f);
        f32 fh = (f32)bh;
        f32 dist = fh / t0;
        f32 half = fw * 0.5f;
        s32 negHeight = -bh;
        func_004A59B8((f32)-bw * 0.5f, half, (f32)negHeight * 0.5f, fh * 0.5f, 0.01f, dist + half, dist);
        RaceEntryCar__update(0);
        func_004A7454();
        f32 zoom = fh0 * 30.0f * 0.03125f;
        func_004A7844(0.0f, 0.0f, -dist);
        func_004A7890(zoom, zoom, zoom);
        func_004A7844(0.0f, height - sy * 0.5f, 0.0f);
        half = sx * 0.5f;
        f32 c = sz * 0.5f;
        f32 r = fw / zoom * 0.5f;
        f32 d2 = c * c + half * half;
        f32 disc = d2 - r * r;
        if (0.0f < disc) {
            f32 root = half * sqrtf_(disc);
            f32 cr = c * r;
            cosv = (cr + root) / d2;
            if (1.0f < cosv || cosv < -1.0f)
                cosv = (cr - root) / d2;
            f32 deg = 180.0f - func_00393CF0(cosv) * 360.0f / 0x1.921fb4p+2f;
            deg *= 0x1.0ccccc0p+0f;
            if (angle < deg)
                angle = deg;
        }
        func_004A7988(2.0f);
        func_004A79B0(angle);
    }
    func_00394A10(self);
    s32 w2 = w * 2;
    s32 h2 = h * 2;
    func_004A1638(5);
    func_004A40B0(0.0f, 1.0f);
    f32 fw2 = (f32)w2;
    f32 fh2 = (f32)h2;
    model->slot2();
    model->slot7(0);
    Light *light = scene->f8->f4->f80;
    f32 saved = light->f58;
    light->f58 = 0.0f;
    func_004A53F8();
    func_004A7844(0.0f, -height, 0.0f);
    func_004567D0(0);
    func_004523E8(0.0f, 0.0f, 0.0f, 1.0f);
    func_00452408(1.0f);
    func_004A29A8(1);
    func_004A1638(5);
    model->slot24(0, 1, 0, 0.0f);
    func_004567D0(1);
    func_004A5400();
    light->f58 = saved;
    func_004A3078(0x80000000);
    func_004A3230(1);
    func_004A6F10(0, 0xFF);
    func_004A29A8(0);
    func_004AA168(0);
    func_004A6140(0, 0, w2, h2);
    func_004A3230(2);
    func_00105728(work);
    func_004A4550(3, 0);
    func_004A4550(2, 0);
    func_004A1638(5);
    func_004A1638(4);
    func_004A26F0(1);
    func_004A2750(7, 0.0f);
    func_004A2980(0);
    func_004A6F10(1, 0xFF);
    f32 ww = (f32)workBuf.width;
    func_004A6788(0.0f, 0.0f, ww, (f32)func_00105818(work), (f32)workBuf.x, (f32)workBuf.y,
                  (f32)(workBuf.x + workBuf.w), (f32)(workBuf.y + workBuf.h));
    func_004AB040(4);
    func_004A26F0(3);
    func_004A2980(0xFFFFFF);
    func_004A2980(0xFF000000);
    func_004A3078(0x80000000);
    func_004A3230(1);
    func_004A2980(-1);
    model->slot20(tex);
    model->slot22(0, 0.0f);
    func_004A6F10(0, 0xFF);
    func_004A29A8(0);
    func_004AA168(0);
    func_004A6140(0, 0, w2, h2);
    func_004AB040(4);
    func_004AB040(6);
    func_004AB040(5);
    func_004AB040(8);
    func_004AB040(3);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
    func_004A2980(0xFF000000);
    func_00105728(work);
    func_001056A0(work);
    func_004AB040(3);
    func_004AB040(4);
    func_004AB040(3);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 2.0f);
    func_004A4910();
    for (s32 i = 0; i < 8; i++)
        func_004A6668(0.0f, 0.0f, fw2, fh2, 0.0f, 0.0f, fw2, fh2);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
    func_00105728(work);
    func_004A1638(3);
    func_004A2858(5, 0.5f);
    func_004A2980(0xFF000000);
    func_004A6140(0, 0, w2, h2);
    func_004AB040(3);
    if (small) {
        func_004A2980(-1);
    } else {
        GSBuffer blurBuf;
        GSBuffer *blur = &blurBuf;
        func_00105338(blur, work, 0);
        func_001056A0(blur);
        func_00105728(work);
        func_004A3040(0.0f, 0.0f, 0.0f, 0.0f);
        func_004A3230(1);
        func_004A4550(3, 0);
        func_004A4550(2, 0);
        func_004A1638(4);
        func_004A28B8(6, 0x40);
        for (s32 j = 0; j < 4; j += 2) {
            for (f32 t = 0.0f; t < 0x1.91eb84p+2f; t += 0x1.91eb84p-1f) {
                f32 dx, dy;
                if (j != 0 || t == 0.0f) {
                    func_0057D8A0(&dx, &dy, t);
                    dx *= (f32)j;
                    dy *= (f32)j;
                    func_004A6668(dx, dy, (f32)w2 + dx, (f32)h2 + dy, 0.0f, 0.0f, (f32)w2, (f32)h2);
                }
            }
        }
        func_004AB040(4);
        func_004A2980(-1);
        func_001056A0(work);
        func_00105728(work);
        func_004A4550(3, 1);
        func_004A4550(2, 1);
        f32 u = (f32)w2 + 0.5f;
        f32 v = (f32)h2 + 0.5f;
        func_004A6668(0.0f, 0.0f, (f32)w2, (f32)h2, 0.5f, 0.5f, u, v);
        func_001056A0(dst);
        func_00105728(blur);
        func_004A4550(3, 1);
        func_004A4550(2, 1);
        func_004A2980(0xFF000000);
        f32 dw = (f32)dst->width;
        func_004A6668(0.0f, 0.0f, dw, (f32)func_00105818(dst), 0.5f, 0.5f, u, v);
        func_004A2980(0xFFFFFF);
        func_00105280(blur, 2);
    }
    func_00105728(work);
    func_001056A0(dst);
    func_004A4550(3, 1);
    func_004A4550(2, 1);
    f32 dw = (f32)dst->width;
    func_004A6668(0.0f, 0.0f, dw, (f32)func_00105818(dst), 0.5f, 0.5f, (f32)w2 + 0.5f, (f32)h2 + 0.5f);
    func_004A2980(-1);
    func_00105280(depth, 2);
    func_00105280(work, 2);
    func_00105280(grad, 2);
    ShowRoomCar__structor_1(&car, 2);
}
