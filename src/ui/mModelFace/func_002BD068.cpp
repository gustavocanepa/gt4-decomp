typedef float f32;
typedef unsigned char u8;

struct Vec3 {
    f32 v[3];
    f32 &operator[](int i) { return v[i]; }
};

extern "C" Vec3 *func_0021A850(u8 *arg0);

extern "C" void func_002BD068(u8 *self, Vec3 *delta) {
    Vec3 *rot = func_0021A850(self + 0xA0);
    if ((*delta)[0] != 0.0f) {
        (*rot)[0] += (*delta)[0];
        while ((*rot)[0] < 0.0f) (*rot)[0] += 360.0f;
        while ((*rot)[0] > 360.0f) (*rot)[0] -= 360.0f;
    }
    if ((*delta)[1] != 0.0f) {
        (*rot)[1] += (*delta)[1];
        while ((*rot)[1] < 0.0f) (*rot)[1] += 360.0f;
        while ((*rot)[1] > 360.0f) (*rot)[1] -= 360.0f;
    }
    if ((*delta)[2] != 0.0f) {
        (*rot)[2] += (*delta)[2];
        while ((*rot)[2] < 0.0f) (*rot)[2] += 360.0f;
        while ((*rot)[2] > 360.0f) (*rot)[2] -= 360.0f;
    }
}
