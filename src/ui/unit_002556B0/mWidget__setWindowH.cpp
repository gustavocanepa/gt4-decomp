typedef float f32;
typedef unsigned char u8;

struct Rect { u8 unused; };
struct Widget {
    u8 pad0[0x34];
    Rect r;
};

extern "C" void mWidget__setWindowGeometry(Widget *self, Rect *r, f32 *px, f32 *py, f32 *pw, f32 *ph);

extern "C" void mWidget__setWindowH(Widget *arg0, f32 fparg0) {
    f32 buf = fparg0;
    mWidget__setWindowGeometry(arg0, &arg0->r, 0, 0, 0, &buf);
}
