typedef float f32;

struct C { char pad[0x34]; int f34; };
extern "C" void func_0025BB18(struct C *, int *, int, float *, int, int);

extern "C" f32 func_0025B9D8(struct C *arg0) {
    float local;
    func_0025BB18(arg0, &arg0->f34, 0, &local, 0, 0);
    return local;
}
