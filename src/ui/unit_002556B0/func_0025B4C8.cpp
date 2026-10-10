typedef float f32;

struct Widget {
    char pad[0x34];
};

struct Rect;

extern "C" void mWidget__setWindowGeometry(struct Widget *self, struct Rect *r, f32 *px, f32 *py, f32 *pw, f32 *ph);

extern "C" void func_0025B4C8(struct Widget *arg0, f32 fparg0, f32 fparg1) {
    f32 sp0 = fparg0;
    f32 sp4 = fparg1;

    mWidget__setWindowGeometry(arg0, (struct Rect *)((char *)arg0 + 0x34), 0, 0, &sp0, &sp4);
}
