typedef float f32;

struct C { char pad[0x34]; int f34; };
extern "C" void mWidget__getWindowGeometry(struct C *, int *, int, int, int, float *);

extern "C" f32 mWidget__getWindowH(struct C *arg0) {
    float local;
    mWidget__getWindowGeometry(arg0, &arg0->f34, 0, 0, 0, &local);
    return local;
}
