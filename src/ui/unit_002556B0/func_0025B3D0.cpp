typedef float f32;

struct C { char pad[0x34]; int f34; };
extern "C" void func_0025B578(struct C *, int *, int, int, int, float *);

extern "C" f32 func_0025B3D0(struct C *arg0) {
    float local;
    func_0025B578(arg0, &arg0->f34, 0, 0, 0, &local);
    return local;
}
