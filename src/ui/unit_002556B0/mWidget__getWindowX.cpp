typedef float f32;

struct C { char pad[0x34]; int f34; };
extern "C" void mWidget__getWindowGeometry(struct C *, int *, float *, float *, int, int);

extern "C" f32 mWidget__getWindowX(struct C *arg0) {
    float local;
    mWidget__getWindowGeometry(arg0, &arg0->f34, &local, 0, 0, 0);
    return local;
}
